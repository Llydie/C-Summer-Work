#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

/**
 * Function that tests if two given numbers are permutations of each other
 * Parameter: long the two numbers to be tested
 * Returns 1 if they are permutations and 0 if not.
*/ 
int isPerm(long num1, long num2) {
    int digits[10];
    int i;
    for (i = 0; i < 10; i++)      // Init all counts to zero.
        digits[i] = 0;
    while (num1 != 0) {           // Process all digits.
        digits[num1%10]++;        // Increment for least significant digit.
        num1 /= 10;               // Get next digit in sequence.
    }
    while (num2 != 0) {           // Same for num2 except decrement.
        digits[num2%10]--;
        num2 /= 10;
    }
    for (i = 0; i < 10; i++)
        if (digits[i] != 0)       // Any count different, not a permutation.
            return 0;
    return 1;                     // All count identical, was a permutation.
}

/**
 * Function that tests each multiple of a number (from 5x to 2x) to see if they are permutations of each other
 * Parameter: the number to test
 * Returns 1 if all multiples are permutations or 0 if not
*/
int isMatched(long number){
    int i;
    int result = 0;
    for (i=5; i>1;i--){             //loop through the multiples to test (5..2)
        long temp = number*i;
        if (!isPerm(number,temp)){  //if it is not a permutation set, return 0
            return 0;            
        }
        
    }
    return 1;                       //otherwise, return 1 since all multiples are permutations
}

/**
 * Main function that tests each number in turn until it finds the first match then prints it.
*/
int main(){
    long i =1;
    while (!isMatched(i)){
        i++;
    }
    printf("The First Number to contain the same digits is: %ld", i);
    return 0;
}