/*Assignment: Q1. Program to find the farthest pair in an array of double values

    (farthest = the difference of the two values is no smaller than the difference of any other pair)
    
    Logically the pair would be the lowest and highest values of the array
    
    Time complexity: O(N)
    
    Date: 26/3/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <stdlib.h> //sizeof()

int main()
{
    double * num; //pointer for array
    double highest;
    double lowest;
    int i;
    int N = 0;
    
    printf("\n\t Find The Farthest Pair Program\n");
    printf("\n How many double values would you like to enter?\n - ");
    scanf("%d", &N);
    
    flushall();
    
    //check error
    
    while(N <= 0)
    {
        printf("\n Error: Too many double values\n - ");
        scanf("%d", &N);
        
        flushall();
        
    } //end while
    
    //allowcate memory using calloc (DMA)
    
    num = (double*)calloc(N, sizeof(double)); //initialises all spaces to 0, no need for byte calculation (malloc) 
    
    printf("\n Enter your values:\n");
    
    //check if memory was allocated
    
    if(num == NULL)
    {
        printf("\n Failed to allocate memory\n");
        
    } //end if
    else
    { 
        //for loop to initialise array and find lowest and highest values
    
        for(i = 0; i < N; i++)
        {
            printf(" - ");
            scanf("%lf", &num[i]);
        
            //Initialise highest and lowest to the first element of the array
        
            if(i == 0)
            {
                highest = lowest = num[0];
            
            }
        
            //If statements to find lowest and highest values in array
        
            if(lowest > num[i])
            {
                lowest = num[i];
            
            } //end if
        
            if(highest < num[i])
            {
                highest = num[i];
            
            } //end if
    
        } //end for
    
        printf("\n The farthest pair in the array is [%.2lf, %.2lf]\n", highest, lowest);
    
        free(num); //release allocated memory
        
    } //end else
    
    flushall(); //borland
    getchar(); //borland
    return 0;
    
} //end main()