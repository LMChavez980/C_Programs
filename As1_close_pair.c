/*Assignment: Q2. Program to find the closest pair of double values in an array

    (closest pair: the difference of the two values is no greater than the difference of any other pair)
    
    Logically these two values would be the 2 smallest values in the array
    
    Time complexity: O(N)
    
    Date: 26/3/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <stdlib.h> //sizeof()

int main()
{
    double * num; //pointer for array
    double low1;
    double low2;
    int N = 0;
    int i;
    
    printf("\n\t Find The Closest Pair Program\n");
    printf("\n How many double values would you like to enter?\n - ");
    scanf("%d", &N);
    
    flushall(); //clear input stream
    
    //check error
    
    while(N <= 0)
    {
        printf("\n Error: Invalid value\n - ");
        scanf("%d", &N);
        
        flushall();
        
    }
    
    //allocate memory using calloc (DMA)
    
    num = (double*)calloc(N, sizeof(double)); //Initialise values to 0, no byte calculation needed (malloc)
    
    //check if memory was allocated
    
    if(num == NULL)
    {
        printf("\n Failed to allocate memory\n");
        
    } //end if
    else
    {
        printf("\n Enter your values:\n");
    
        //for loop to initialise array and find the 2 lowest values
    
        for(i = 0; i < N; i++)
        {
            printf(" - ");
            scanf("%lf", &num[i]); //LF
        
            //if i is 0 initialise low1 to the first element of the array
        
            if(i == 0)
            {
                low1 = num[0];
            
            } //end if
        
            //if i is 1 initialise low2 to the second element of the array
        
            if(i == 1)
            {
                low2 = num[1];
            
            } //end if
        
            //if entered value is less than low1 then put current low1 into low2 and then put entered value into low1
        
            if(num[i] < low1)
            {
                low2 = low1;
                low1 = num[i];
            
            } //end if
        
            //if entered value is not equal to low1 but is less than current low2 put entered value into low2
        
            if(num[i] != low1 && num[i] < low2)
            {
                low2 = num[i];
            
            } //end if
        
        } //end for
    
        printf("\n The closest pair in the array is [%.2lf, %.2lf]\n", low1, low2);
    
        free(num); //release allocated memory
        
    } //if else
    
    flushall(); //borland
    getchar(); //borland
    return 0;
    
} //end main()