/*Program that implements a queue using an array, using an input string to queue or dequeue

    Date: 10/4/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <string.h>

#define MAX 101

//Function prototypes

void enqueue(char[], char, int *, int *, int *);
void dequeue(char[], int *, int *, int *);
void dsp(char[], int, int);

int main()
{
    char input[MAX];
    char queue[MAX];
    char data;
    int head, tail;
    int i, len;
    int check = -1;
    int j = 0;
    
    head = -1;
    tail = -1;
    
    do
    {
        printf("\n Input any string (100 chracters MAX)\n Include '*' to dequeue\n Enter 'exit' to terminate\n\n - ");
        scanf("%s", input);
        
        check = strcmp(input, "exit");
        
        if(check == 0)
        {
            return 0; //exit code
            
        } //end if
        else
        {
            len = strlen(input);
            
            while(len > MAX-1)
            {
                printf("\n Input any string (100 chracters MAX)\n Include '*' to dequeue\n Enter 'exit' to terminate\n\n - ");
                scanf("%s", input);
                
                len = strlen(input);
                
            } //end while
            
            for(i = 0; i < len; i++)
            {
                data = input[i];
                
                if(data == '*')
                {
                    dequeue(queue, &head, &tail, &j);
                    
                } //end if
                else
                {
                
                    enqueue(queue, data, &head, &tail, &j);
                    
                } //end else
                
                dsp(queue, head, tail);
                
            } //end for
            
        } //end else
        
    }
    while(true);
    
} //end main

//Implement enqueue(): Function to enqueue an element into the queue

void enqueue(char queue[], char data, int * head, int * tail, int * j)
{
    printf("\n Enqueuing: %c\n", data); 
    
    //if first element entered
    
    if(*j == 0)
    {
        queue[*j] = data;
        *head = 0;
        *tail = 0;
        (*j)++;
    }
    else
    {
        (*tail)++;
        queue[*tail] = data;
        
    } //end else
    
} //end enqueue()

//Implement dequeue(): Function to dequeue an element from the queue

void dequeue(char queue[], int * head, int * tail, int * j)
{
    int k;
    
    //If no elements in queue
    
    if(*head == -1 && *tail == -1)
    {
        return; //return to main
        
    } //end if
    
    printf("\n Dequeuing: %c\n", queue[*head]);
    
    //loop to move the elements forward towards head
    
    for(k = 0; k < (*tail)+1; k++)
    {
        queue[k] = queue[k+1];
        
    } //end while
    
    queue[*tail] = NULL;
    
    //decrease size of queue
    (*tail)--;
    
    //if tail meets head reset tail and head
    
    if(*tail == -1)
    {
        *head = -1;
        *j = 0;
        
    } //end if
    
} //end dequeue()
    
//Implement dsp(): Function to display queue

void dsp(char queue[], int head, int tail)
{
    int k;
    
    //if no elements in queue
    
    if(head == -1 && tail == -1)
    {
        printf("\n Empty Queue\n");
        
        return; //return to main
        
    } //end if
    
    printf("\n Queue: ");
    
    for(k = 0; k < tail+1; k++)
    {
        printf("%c ", queue[k]);
        
    } //end while
    
    printf("\n");
    
} //end dsp()