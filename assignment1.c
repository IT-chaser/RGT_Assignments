#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROBOT_WIDTH 800
#define ROBOT_HEIGHT 1200
#define MOVE_DISTANCE 50
#define CLEARANCE 100

// Simulated lidar data
const char *lidarData[] = {
    "0,252", "1,250", "2,248",
};

/// @brief Get lidar data
/// @param None
/// @return Lidar data “degree,distance”
const char * GetLidarData(void)
{
    static int index = 0;
    const char *data = lidarData[index];
    index = (index + 1) % (sizeof(lidarData) / sizeof(lidarData[0]));
    return data;
}

/// @brief Check obstacle for forward move
/// @param None
/// @return 1 : OK to go, 0 : impossible to go
int CheckForForward (void)
{
    const char *data = GetLidarData();
    int angle, distance;
    sscanf(data, "%d,%d", &angle, &distance);

    // Calculating position of obstacle
    double obstacleX = distance * cos(angle * 0.0174533); // converting degrees to radians
    double obstacleY = distance * sin(angle * 0.0174533); // converting degrees to radians

    // Calculating position of robot after movement
    double robotX = obstacleX - MOVE_DISTANCE;
    double robotY = obstacleY;

    // Check if there is enough clearance
    if (robotX >= -ROBOT_WIDTH / 2 + CLEARANCE && robotX <= ROBOT_WIDTH / 2 - CLEARANCE &&
        robotY >= 0 && robotY <= CLEARANCE) {
        return 1; // OK to go
    } else {
        return 0; // Impossible to go
    }
}

int main(void)
{
    // Test the CheckForForward function
    printf("Forward move possible: %s\n", CheckForForward() ? "Yes" : "No");
    return 0;
}