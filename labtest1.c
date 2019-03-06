/*Program Description: Program to implement the Fibonacci series 
    Author: Louis Chavez
    Date: 23/10/17
*/

#include <stdio.h>

int main()
{
    int i;
    int terms;
    int num1, num2;
    int total;
    
    num1 = 0;
    num2 = 1;
    
    printf("\n Enter number of terms to be sequenced \n");
    printf(" - ");
    
    scanf("%d", &terms);
    
    flushall(); //exe doesn't close
    
    printf("\n\n %d %d ", num1, num2);
    
    // Use for loop to repeat algorithm
    
    for(i = 2; i < terms; i++) //i = 2 because first two terms are given 0 and 1
    {
        total = num2 + num1;
        printf("%d ", total);
        num1 = num2;
        num2 = total;
        
    } //end for
    
    getchar();
    return 0;
    
} //end main()
    
        
    
    

    
    
    
    
    
    
    