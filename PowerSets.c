//Algorithmic time complexity = n * 2^n
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>


/**
 *Function that prints the Power Set of a given set to the terminal
 *Parameter: A pointer to the set to find the power set of 
 *Parameter: The size of the set passed in
*/
void printPowerSet(char *set, int size){
    int PSet_size = pow(2,size);
    int counter, i;
    for (counter = 0; counter < PSet_size; counter++){
        printf("{");
        for (i = 0; i < size; i++){
            if (counter & (1<<i)){
                printf("%c", set[i]);
            }
        }
        printf("}");
        printf("\n");
    }
}

/**
 * Main function that specifies the set and makes the call to print the power set
 * TODO: allow the user to enter the power set themselves
*/
int main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);
    char set[] = {'a','b','c'};
    printPowerSet(set,3);
    gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec - start.tv_usec / 1e6; //time in seconds
    printf("time program took %f seconds to execute\n", time_taken);
    return 0;
}