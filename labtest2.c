/*Program Description: 
    Given the following arrays:
    
        float gallons[5];
        float miles[5];
        float mpg[5];
        
    Write a program, using pointer notation only, to do the following:
    1. Enter values into the gallons array and miles array.
    2. Calculate and fill the mpg array using the values contained in the gallons
    array and miles array with the formula:
    
        mpg = miles / gallons
        
    3. Display the contents of the mpg array.

    Date: 4/12/17
    Author: Louis Chavez
    
    array_name[i] = *(array_name + i)
*/

#include <stdio.h>
#define SIZE 5

int main()
{
    float gallons[SIZE];
    float miles[SIZE];
    float mpg[SIZE];
    
    int i; //index - for loops
    
    //Enter in values for gallons array
    
    printf("\n Enter 5 values for gallons \n");
    
    for(i = 0; i < SIZE; i++)
    {
        printf(" - ");
        scanf("%f", &*(gallons + i)); //&gallons[i] - dereference operator used to insert values: point to address, put value inside
        
    } //end for
    
    //Enter 5 values for for miles array
    
    printf("\n Enter 5 values for miles \n");
    
    for(i = 0; i < SIZE; i++)
    {
        printf(" - ");
        scanf("%f", &*(miles + i)); //&mile[i]
        
    } //end for

    //Calculate and initialise mpg
    
    for(i = 0; i < SIZE; i++)
    {
        *(mpg+ i) = ((*(miles + i)) / (*(gallons + i))); //mpg[i] = miles[i] / gallons[i]
        
    } //end for
    
    //Display contents of mpg array
    
    printf("\n mpg contains: ");
    
    for(i = 0; i < SIZE; i++)
    {
        printf("\n - ");
        printf("%.2f", *(mpg + i)); //&mpg[i] - %.2f to display with 2 decimal points
        
    } //end for
    
    flushall(); //exe won't close
    getchar(); //exe won't close
    return 0;
    
} //end main()