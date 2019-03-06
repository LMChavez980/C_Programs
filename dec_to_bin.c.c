/*Write a C program to convert decimal number into binary number

    array_name[i] = *(array_name + i)

    Date: 12/2/18
    Author: Louis Chavez
*/

#include <stdio.h>
#define SIZE 10
#define DIV 2

//Prototype

void dec_to_bin(int); //no return value, passing int

int main()
{
    int dec_num;
    
    printf("\n Enter a decimal number to be converted to binary\n");
    printf(" - ");
    scanf("%d", &dec_num);
    
    //Call function
    
    dec_to_bin(dec_num); //pass by value; copy value of dec_num
    
    flushall(); //borland
    getchar(); //borland
    return 0;
    
} //end main()

//Implement dec_to_bin()

void dec_to_bin(int decimal)
{
    int binary[SIZE];
    int i;
    
    printf("\n Decimal value: %d\n", decimal);
    
    //Initialise array until decimal hits 0
    
    for(i = 0; decimal > 0; i++)
    {
        binary[i] = decimal % DIV; //subscript notation
        //printf(" binary[%d] = %d\n", i, binary[i]); testing
        decimal = decimal / DIV;
        
    } //end for

    printf("\n Binary value: ");
    
    //Display binary value using array
    
    for(i = i - 1; i > -1; i--) //i value from last for loop; i > -1 so that first element is displayed
    {
        printf("%d", *(binary + i)); //pointer notation
        
    } //end for
    
} //end dec_to_bin()
