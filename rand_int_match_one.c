/*Write a program to generate M random integers and puts them in an array, then count the
    number of N Random Integers that matches one of the numbers in Array, using sequential
    search. Run your program for M= 10, 100, 1000 and N= 10, 100, 1000.
    
    Date: 19/2/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <stdlib.h> //srand() & rand()
#include <time.h> //time(NULL)

/*Adjust symbolic names for testing:
    if M = 10 then TEST = 9
    if M = 100 then TEST = 99
    if M = 1000 then TEST = 999
*/

#define M 10
#define N 1000
#define TEST 9 

int main()
{
    int num[M];
    int check;
    int i;
    int count = 0;
    int match;
    
    //random sequence of numbers every program run - if number is used same sequence will remain static every run
    srand(time(NULL));
    
    printf("\n M = %d: ", M);
    
    //Put 10 random integers in an array
    
    for(i = 0; i < M; i++)
    {
        num[i] = 1 + rand() % 100; //to set range: first number + rand() % last number
        printf("%d ", num[i]);
        
    } //end for
    
    //Select random element from num array to check with check array
    match = 0 + rand() % TEST; //elements in array from 0 - n
    printf("\n\n Selected number = %d \n\n Checking for matches with %d random integers....\n", num[match], N);
    
    //Random number will be generated and checked with selected element from num array
    
    for(i = 0; i < N; i++)
    {    
        check = 1 + rand() % 100;
        
        if(check == num[match])
        {
            count++;
            
        } //end if

    } //end for
    
    printf("\n No. of matches found = %d \n", count);
    
    getchar(); //borland
    return 0;
    
} //end main()