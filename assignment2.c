#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define UART_BAUD_RATE 9600

/// @brief Initialize CPU registers and interrupt
/// @param None
/// @return 0 if fail
int InitCPU(void) {
    return 1; // Success
}

/// @brief Initialize External sensors
/// @param None
/// @return 0 if fail
int InitSensor(void) {
    srand(time(NULL)); // Seed random number generator
    return 1; // Success
}

/// @brief Send 1 byte data to UART
/// @param data : Data to be sent to UART
/// @return 0 if fail
int SendUart(unsigned char data) {
    printf("Data sent via UART: %d\n", data);
    return 1; // Success
}

/// @brief Get temperature
/// @param channel : temperature channel
/// @return temperature. -300 if fail
int GetTemperature(int channel) {
    int temperature = rand() % 401 - 200; // Range: -200 to 200
    return temperature;
}

/// @brief Get humidity
/// @param None
/// @return humidity. -1 if fail
int GetHumidity(void) {
    int humidity = rand() % 101; // Range: 0 to 100
    return humidity;
}

/// @brief Timer interrupt. Set to once in 10msec
/// @param None
/// @return None
void Timer1a(void) {
    // Code for timer interrupt handling
}

int main(void) {
    // Initialize CPU and sensors
    if (!InitCPU() || !InitSensor()) {
        printf("Initialization failed.\n");
        return 1;
    }

    // Main loop
    while (1) {
        // Read temperature and humidity
        int temperature = GetTemperature(0); // Assuming one temperature channel
        int humidity = GetHumidity();

        // Check for noise (10% probability)
        if (rand() % 10 == 0) {
            temperature += rand() % 21 - 10; // Add noise to temperature (-10 to 10)
            humidity += rand() % 21 - 10;    // Add noise to humidity (-10 to 10)
        }

        // Send data via UART
        unsigned char data[5]; // Arbitrary data format
        data[0] = temperature >> 8; // MSB of temperature
        data[1] = temperature & 0xFF; // LSB of temperature
        data[2] = humidity >> 8; // MSB of humidity
        data[3] = humidity & 0xFF; // LSB of humidity
        data[4] = '\n'; // End of data marker
        for (int i = 0; i < 5; i++) {
            SendUart(data[i]);
        }

        // Delay for 1 second
        sleep(1);
    }
    return 0;
}
