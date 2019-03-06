/*Assignment: Q4 Program that will..

    (i). Delete the ith element from an unsorted array without relying on array size N
    (ii). Delete the ith position of a sorted array without relying on the size N

    DMA is used to allocated to user's requested size N
    
    Time complexity: O(N^2) 
    
   (i). Deletion process time complexity: O(1)
   (ii). Deletion process time complexity: O(1)
   
    The method used in (ii) is not a proper deletion of the element and rescaling of the array so that elements stay.
    Instead of actually deleting and rescaling, the value to be deleted is replaced by a value 0 and using conditions,
    the user is no longer able to access the array position. The array size is not rescaled for to do so the code would have
    to rely of the size N of the array to move values, instead the user cannot delete from already deleted positions.
    Once the array is empty the user has the option to terminate and generate a set of numbers.

    Date: 3/4/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <stdlib.h> //srand() and rand()
#include <string.h> //string functions

#define MIN 1
#define MAX 100

//function prototypes

void generate(int * , int *, int, int *, int *); //Function to generate random numbers (4 pointer, 1 normal pass)

//(i) Delete ith element of unsorted array
void dlt_un(int *, int *); //Function to delete numbers from array a (2 pointers)
void display_un(int *, int *); //Function to display numbers of array a (2 pointers)

//(ii) Delete ith element of sorted array
void dlt_so(int *, int, int *); //Function to delete numbers from array b (2 pointers, 1 normal pass)
void display_so(int *, int, int *); //Function to display numbers of array b (2pointer, 1 normal pass)
void sort(int *, int); //Function to sort array b - using Selection sort (1 pointer, 1 normal pass)

int main()
{
    int N = 0; //index for a
    int * a; //array a
    int * b; //array b
    int empty = 0; //empty counter for (ii)
    char input[MIN]; //user input
    int check1, check2, check3, check4; //strcmp
    int K; //index for b 
    
    check1 = check2 = check3 = 1;
    
    //Prompt for array size
    
    printf("\n How many items would you like to store in the array?\n - ");
    scanf("%d", &N);
    
    flushall(); //clear input stream
    
    //check for input error
    
    while(N <= 0)
    {
        printf("\n Error: Invalid amount entered\n - ");
        scanf("%d", &N);
        
    } //end while
    
    K = N; //initialise K index to equal N
    
    //Allocate memory to a using malloc() - requires calculation of bytes
    
    a = (int*)malloc(N * sizeof(int));
    b = (int*)malloc(N * sizeof(int));
    
    //check if memory allocation was successful
    
    if(a == NULL || b == NULL)
    {
        printf("\n Error: Failed to allocate memory\n");
        
    }//end if
    else
    {
        //generate numbers - pass by reference for N and empty
        
        generate(a, b, K, &N, &empty);
        
        //Loop while user has not enetered exit code
        
        while(check4 != 0)
        {
            printf("\n Enter '1' to delete from unsorted array (a)\n Enter '2' to delete from sorted array (b)\n Enter '3' to get new numbers for both arrays\n Enter '4' to terminate\n - ");
            scanf("%s", input);
            
            check1 = strcmp(input, "1");
            check2 = strcmp(input, "2");
            check3 = strcmp(input, "3");
            check4 = strcmp(input, "4");
            
            //1
            if(check1 == 0)
            {
                //Call dlt_un()
                dlt_un(a, &N); //(i)
                
            } //end if
            
            //2
            if(check2 == 0)
            {
                //Call dlt_so()
                dlt_so(b, K, &empty); //(ii)
                
            } //end if
            
            //3
            if(check3 == 0)
            {
                //Call generate()
                generate(a, b, K, &N, &empty);

            } //end if                
            
            //error check if not 1-4
            if(check1 != 0 && check2 != 0 && check3 != 0 && check4 != 0)
            {
                printf("\n Error: Invalid input\n");
                
            } //end if
            
        } //end while
        
        free(a); //free allocated memory for a
        free(b); //free allocated memory for b
        
    } //end else
    
    getchar(); //borland
    return 0;
    
} //end main()

//Implement generate(): Function that will generate N random numbers between a given range

void generate(int * a, int * b, int K, int * N, int * empty)
{
    int i;
    static int j = 0; //static counter - to change seed value
    
    j++;
    
    *empty = 0; //empty counter reinitialised to 0
    
    srand(j); //seed value gives constant list of random numbers
    
    for(i = 0; i < K; i++)
    {
        a[i] = MIN + rand() % MAX; //numbers between a range
        b[i] = MIN + rand() % MAX;
        
    } //end for
    
    *N = K; //reinitialise N
    
    //display for a
    
    display_un(a, N);
    
    //display for b
    
    printf("\n Pre-sort || ");
    
    display_so(b, K, empty);
    
    sort(b, K);
    
    printf("\n Post-sort || ");
    
    display_so(b, K, empty);
    
} //end generate()

//Implement dlt_un(): Function will delete the value in the ith position in the array

void dlt_un(int * a, int * N)
{
    int choice = 0;
    int temp = 0; //temporary variable
    
    printf("\n");
    
    display_un(a, N);
    
    //if array has not been emptied
    
   if((*N -1) != -1)
   {
        printf("\n\n Which array position do you want to delete from?[0 - %d]\n - ", (*N)-1);
        scanf("%d", &choice);
    
        flushall();
    
       //check for error input
       
        while(choice <= -1 || choice > (*N-1))
        {
            printf("\n Error: Invalid amount entered\n - ");
            scanf("%d", &choice);
        
        } //end while
        
        //(i) **Deletion process**
    
        temp = a[choice];
        a[choice] = a[(*N)-1];
        a[(*N)-1] = temp;
    
        printf("\n a[%d]: %d has been deleted\n\n", choice, a[(*N)-1]);
        
        (*N)--; //decrement N - rescale array
        
    } //end if
    else
    {
        printf("\n There are no more elements in the array\n");
        
    } //end else
    
} //end dlt_un()

//Implement dlt_so(): Function that will delete the ith element of the sorted array

void dlt_so(int * b, int K, int * empty)
{
    int choice = 0;
    int temp = 0; //temporary variable 
    int i;
    
    printf("\n");
    
    display_so(b, K, empty);
    
    //if empty is equal to size - Array is empty
    
   if(*empty != K)
   {
        printf("\n\n Which array position do you want to delete from?[0 - %d]\n - ", K-1);
        scanf("%d", &choice);
    
        flushall();
    
       //check for error input
       
        while(choice <= -1 || b[choice] == 0 || choice == K)
        {
            printf("\n Error: Invalid amount entered - out of range or already deleted\n - ");
            scanf("%d", &choice);
        
        } //end while
        
        //(ii). **Deletion process**
        
        temp = b[choice];
        b[choice] = 0;
        (*empty)++; //increment empty counter
        
        printf("\n b[%d]: %d has been deleted\n", choice, temp);
        
    } //end if
    else
    {
        printf("\n There are no more elements in the array\n");
        
    } //end else
    
} //end dlt_so()

//Implement display_un(): Function will display the numbers of array a

void display_un(int * a, int * N)
{
    int i;
    
    printf(" a[]: ");
    
    if((*N - 1) != -1)
    {
        for(i = 0; i < *N; i++)
        {
            printf("%d ", a[i]);
        
        } //end for
        
    }//end if
    else
    {
        printf(" **Empty**\n");
        
    } //end else
    
    printf("\n");
    
} //end display_un()

//Implement display_so(): Function will display the numbers of array b

void display_so(int * b, int K, int * empty)
{
    int i;
    
    printf(" b[]: ");
    
    if(*empty != K)
    {
        for(i = 0; i < K; i++)
        {
            if(b[i] != 0)
            {
                printf("%d ", b[i]);
            
            } //end if
        
        } //end for
        
    } //end if
    else
    {
        printf(" **Empty**\n");
        
    } //end if
    
    printf("\n");
    
} //end display_so()

//Implement sort(): Function that will sort array using selection sort

void sort(int * b, int N)
{
    int i, j, min, temp;
    
    //Selection sort - always find smallest first
    
    for(i = 0; i < (N - 1); i++) //n-1 so that is doesn't check final element - largest
    {
        min = i; //minimum will move with i
        
        for(j = i + 1; j < N; j++)
        {
            if(b[min] > b[j])
            {
                min = j; //minimum changes if something in array is smaller than minimum
                
            } //end if
            
        } //end inner for
        
        if(min != i)
        {
            //swap value in minimum and i if there nother else is smaller after passing
            temp = b[i];
            b[i] = b[min];
            b[min] = temp;
            
        } //end if
        
    } //end outer for
    
} //end sort()