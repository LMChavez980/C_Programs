/*Assignment: Q3. Program implementing a stack with a single queue
    so that the stack operations are linear to queue operations
    
    Stack implemented using linked list with "queue configuration" (FIFO) - Pushdown Stack
    head -> dequeue (pop)
    tail -> enqueue (push)
    
    Time complexity:  O(N^2)
    
    Date: 30/3/18
    Author: Louis Chavez
    
*/

#include <stdio.h>
#include <stdlib.h> //sizeof
#include <string.h> //string functions

#define MAX 100

struct node
{
    char data;
    struct node * next;
    
}; //end node

//Global pointer variables for pointing to the head and tail of queue - global scale

struct node * head = NULL; //top of stack
struct node * tail = NULL; //bottom of stack
    
//Function prototypes

void enqueue(char); //function to enqueue values (push into stack)
void print_q(); //function to print values
void dequeue(); //function to dequeue values (pop out of stack)

int main()
{
    char input[MAX];
    char choice;
    int len, i, check;
    
    do
    {
        printf("\n Input any string of characters to enqueue. (No Spaces, %d characters MAX)\n Enter '*' to dequeue\n Enter 'exit' to exit\n\n - ", MAX);
        scanf("%s", input);
        
        len = strlen(input); //finds length of input string
        
        //while loop for error check - string entered must be properly null terminated
        
        while(len > (MAX - 1))
        {
            printf("\n Error: MAX characters exceeded (Less than or equel to %d characters input only)\n - ", MAX - 1);
            scanf("%s", input);
            len = strlen(input);
            
        } //end while
        
        check = strcmp(input, "exit"); //check input with exit string - returns integer value
        
        if(check == 0)
        {
            return 0;
            
        } //end if
        
        //check characters inputted
        
        for(i = 0; i < len; i++)
        {
            choice = *(input + i); //pointer notation
            
            if(choice == '*')
            {
                dequeue(); //pop
                
            }
            else
            {
                //Add to end of list - pushing the top up the stack
                
                enqueue(choice); //push
    
                //Display contents of queue
    
                print_q();
            
            } //end else
        
        } //end for
        
    }
    while(true); //end do while
    
} //end main()

//Implement enqueue: Function that will create a new node and add it to the end of queue - pushdown stack 

void enqueue(char val)
{
    //create node
    struct node * temp = (node*)malloc(sizeof(node));
    
    printf("\n Enqueuing: %c\n", val);
    
    //store value in new node
    temp->data = val;
    //point new node to nothing
    temp->next = NULL;
    
    //Check if val is first value in the list
    
    if(head == NULL && tail == NULL)
    {
        //address of new node is current head and tail
        head = tail = temp;
        
        return; //return to main
        
    } //end if
    
    //make tail point to temp
    tail->next = temp;
    //address of tail is now adress of new node
    tail = temp;
    
} //end enqueue()

//Implement dequeue(): Function to remove value from top of queue - pop first value inputted

void dequeue()
{
    //Create temporary node
    struct node * temp = NULL;
    char val;
    
    //If queue is empty - head & tail pointing to nothing
    if(head == NULL && tail == NULL)
    {
        printf("\n Empty: Stack Underflow\n");
        
        return; //return to main
        
    } //end if
    
    //address that head is pointing to is put into temp
    temp = head->next;
    val = head->data;
    printf("\n Dequeing: %c\n", val);
    //address of current head is released - memory is deallocated
    free(head);
    //address that head was previously pointing to is now the new head
    head = temp;
    
    //if head is at NULL (end) then queue is empty therefore tail should also be NULL
    //if user pops all values in queue, reinitialise head and tail
    if(head == NULL)
    {
        tail = NULL;
        printf("\n Empty stack\n");
        
        return; //return to main
        
    } //end if
    
    print_q();
    
} //end dequeue()

//Implement print_q(): function to display queue

void print_q()
{
    struct node * temp = head;
    
    printf("\n Queue:");
    
    //while loop will go through list and print until it arrives at the end
    
    while(temp != NULL)
    {
        printf(" %c ", temp->data);
        temp = temp->next;
        
    } //end while()
    
    printf("\n");
    
} //end print_q()