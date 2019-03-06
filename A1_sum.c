/* Write a C program to compute the following sum

    N = 100
    SIGMA  1/i
    i  1
    
    Date: 6/2/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <time.h>
#define SIZE 1 //no hardcoding

int main()
{
    clock_t begin = clock(); //start clock
    
    int i;
    int N = 1000000;
    float sum = 0;
    
    for(i = 1; i < N + SIZE ; i++) //since i starts at 1, n = 101 for loop
    {
        sum = sum + (SIZE/(float)i); //casting
        //testing
        //printf("\n Previous + %d/%d is = %f", SIZE, i, sum);
        
    } //end for
    
    printf("\n The sum is %f", sum);
    
    clock_t end = clock(); //end clock
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; 
    
    printf("\n Time: %f seconds", time_spent); //display time in seconds
    
    getchar();
    return 0;
    
} //end main
    