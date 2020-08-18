#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

/**
 * Function that converts the decimal number into binary and counts the 1s in this binary number
 * Parameter: the decimal number to convert
 * Returns the number of 1s present in the converted binary number
 */
int countOnes(int dec){
    int result = 0;
    int i = 0;
    int binDigit = dec%2;
    int decCurrent = dec/2;
    if (binDigit == 1){
        result++;
    }
    while (decCurrent != 0){
        i++;
        binDigit = decCurrent%2;
        if (binDigit == 1){
            result++;
        }
        decCurrent = decCurrent/2; 
    }
    return result;
}

/**
 * Main function that allows the user to enter an integer and then prints 
 * how many 1s are in the binary representation.
 * Returns 0 if successful
 */
int main(){
    int userInt;
    printf("Enter the decimal number: ");
    scanf("%d", &userInt);
    int final = countOnes(userInt);
    printf("There are %d 1s in the unsigned binary representation", final);
    return 0;
}