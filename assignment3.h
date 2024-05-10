/// @brief Calculate the length of a string
/// @param string : Pointer to the string
/// @return Length of the string
int RGTStrLen(unsigned char *string)
{
    int length = 0;
    while (*string != '\0') {
        length++;
        string++;
    }
    return length;
}

/// @brief Copy one string to another
/// @param dest : Destination string
/// @param src : Source string
/// @return Pointer to the destination string
unsigned char *RGTStrCopy(unsigned char *dest, unsigned char *src)
{
    unsigned char *temp = dest;
    while (*src != '\0') {
        *temp = *src;
        temp++;
        src++;
    }
    *temp = '\0'; // Null-terminate the destination string
    return dest;
}

/// @brief Concatenate two strings
/// @param dest : Destination string
/// @param src : Source string to be concatenated to the destination
/// @return Pointer to the destination string
unsigned char *RGTStrCat(unsigned char *dest, unsigned char *src)
{
    unsigned char *temp = dest;
    // Move to the end of the destination string
    while (*temp != '\0') {
        temp++;
    }
    // Append the source string to the destination string
    while (*src != '\0') {
        *temp = *src;
        temp++;
        src++;
    }
    *temp = '\0'; // Null-terminate the concatenated string
    return dest;
}

/// @brief Compare two strings
/// @param str1 : First string
/// @param str2 : Second string
/// @return 0 if strings are equal, negative value if str1 is less than str2, positive value if str1 is greater than str2
int RGTStrCmp(unsigned char *str1, unsigned char *str2)
{
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0; // Strings are equal
        }
        str1++;
        str2++;
    }
    return *str1 - *str2; // Return the ASCII difference
}
