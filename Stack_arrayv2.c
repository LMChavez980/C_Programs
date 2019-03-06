/*Program to demonstrate stack implementation using an array
    
    Date: 19/03/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <string.h>
#include <conio.h> //clrscr();

#define MAX 100

//Prototypes

void push(char[], int *, char[], int); //int * for pass by reference
char pop(char[], int *); 
void display(char[], int *);

int main()
{
    char stack[MAX];
    char val[MAX];
    char data;
    int top = -1;
    int i, len;
    
    printf("\n Enter an input string\n - ");
    scanf("%s", val); 
    clrscr();
    
    len = strlen(val);
    
    for(i = 0; i < len; i++)
    {
        printf("\n Input: %c\n", val[i]);
        
        //If asterisk is entered pop else if not exit code '@', push input
        
        if(val[i] == '*')
        {
            data = pop(stack, &top); //pass by reference
            
            if(data != '\0')
            {
                printf("\n \"%c\" was popped\n", data);
                
            } //end if
            
            display(stack, &top);
            
        }
        else
        {
            push(stack, &top, val, i);
            display(stack, &top);
        
        } //end if
        
    } //end for
    
    flushall();
    getchar();
    return 0;
    
} //end main()

//Implement push()

void push(char stack[MAX], int * top, char val[MAX], int i)
{
    if((*top) >= MAX-1)
    {
        printf("\n ~~Stack Overflow!~~\n");
        
    } //end if
    else
    {
        (*top)++;
        stack[*top] = val[i];
        printf("\n \"%c\" was pushed\n", stack[*top]);
        
    } //end else
    
} //end push()

//Implement pop()

char pop(char stack[MAX], int * top)
{
    char free;
    
    if((*top) <= -1)
    {
        printf("\n ~~Stack Underflow!~~\n");
        free = NULL;
        
        return free;
        
    } //end if
    else
    {
        free = stack[*top];
        (*top)--;
    
        return free;
        
    } //end else
    
} //end pop()

//Implement display()

void display(char stack[], int * top)
{
    int i;
    
    if((*top) >= 0)
    {
        printf("\n Stack Contents:\n");
        
        for(i = (*top); i >= 0; i--)
        {
            printf(" %c\n", stack[i]);
            
        } //end for
    }
    else
    {
        printf("\n **Stack Empty**\n");
    }
    
} //end display