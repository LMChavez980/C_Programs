/*Program  to sort a number of elements 3 ways and measure their times
    (i) Selection Sort
    (ii) Merge Sort
    (iii) Quick Sort
    
    Date: 7/3/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <stdlib.h> //srand() and rand()
#include <time.h> //time(NULL)
#include <conio.h> //clrscr

#define SIZE 10000 //amount that gets results
#define MAX 10000
#define MIN 1

//Prototype

void sel_sort(int[]);
int *generate(int[]);
//void print(int[]);
void mer_sort(int[], int, int);
void merge(int[], int, int, int, int);

//Implement compare function for qsort

int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    char options;
    int num[SIZE];
    
    do
    {
        //Call generate()
        
        generate(num);
        
        printf("\n Choose a sorting algorithm:\n");
        printf("\n 1: Selection Sort\n");
        printf("\n 2: Merge Sort\n");
        printf("\n 3: Quick Sort\n");
        printf("\n 4: Exit\n\n");
        
        printf(" - ");
        scanf("%1s", &options);
        
        switch(options)
        {
            case '1':
            {
                //Call Sel_sort()
                
                clrscr();
                
                clock_t begin = clock(); //start clock
                
                sel_sort(num);
                
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                
                printf("\n n = %d\n\n Selection Sort: %f ms\n", SIZE, time_spent);
    
                //print(num);
                
                break;
                
            } //end case 1
            
            case '2':
            {
                //Call Mer_sort()
                
                clrscr();
                
                clock_t begin = clock(); //start clock
                
                mer_sort(num, 0, SIZE - 1);
                
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                
                printf("\n n = %d\n\n Merge Sort: %f ms\n", SIZE, time_spent);
    
                //print(num);
                
                break;
                
            } //end case 2
            
            case '3':
            {
                //Call qsort()
                
                clrscr();
                
                clock_t begin = clock(); //start clock
                
                qsort(num, SIZE, sizeof(int), cmpfunc);
                
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                
                printf("\n n = %d\n\n Quick Sort: %f ms\n", SIZE, time_spent);
                
                //Call print()
                //print(num);
                
                break;
                
            } //end case 3
            
            case '4':
            {
                return 0;
                
            } //end case 4
            
            default:
            {
                clrscr();
                
                printf("\n Wrong Input\n");
                
                break;
                
            } //end default
            
        } //end switch
        
    }
    while(true); 
    
} //end main()

//Implement generate()

int *generate(int num[])
{
    int i;
    
    srand(time(NULL));
    
    //printf("\n Pre-sorted numbers: ");
    
    //Initialise array with random integers
    
    for(i = 0; i < SIZE; i++)
    {
        num[i] = MIN + rand() % MAX;
        //printf(" %d ", num[i]);
        
    } //end for
    
    printf("\n");
    
    return num;
    
} //end generate()

//Implement print()

/*void print(int num[])
{
    int i;
    
    printf("\n\n ----------------------------------------------------------\n");
    printf("\n Sorted numbers: ");
    
    //Display sorted array
    
    for(i = 0; i < SIZE; i++)
    {
        printf(" %d ", num[i]);
        
    } //end for
    
    printf("\n\n ----------------------------------------------------------\n");
    
} //end print()*/

//Implement sel_sort()

void sel_sort(int num[])
{
    int i, j;
    int min;
    int swap;
    
    /*Initiate sorting -
            Loop will keep checking until it gets to the end of the array[i] 
            where the last element in this case is now the largest number
        */
    
    for(i = 0; i < (SIZE - 1); i++) //last element a[9] 
    {
        min = i; //Set minimum to i element
        //minimum will move with i 
        
        for(j = i + 1; j < SIZE; j++)
        {
            //check all the elements of the array if any are bigger than minimum
            
            if(num[min]> num[j])
            {
                //Switch minimum position if other array element is bigger than current minimum
                min = j;
                //continue to check other elements after (if any)
                
            } //end if
            
        } //end inner for 
        
        //if the current minimum position is not at original minimum position  
        
        if(min != i)
        {
            //swap contents of a[i] with a[min] - direct switching of contents with a[0] regardless of position in array
            swap = num[i];
            num[i] = num[min];
            num[min] = swap;
            
        } //end if
        
    } //end outer for
    
} //end sel_sort()

//Implement mer_sort()

void mer_sort(int num[],int i,int j)
{
    int mid;
    
    if(i < j)
    {
        mid = (i + j) / 2;
        mer_sort(num, i, mid); //left recursion
        mer_sort(num, mid + 1, j); //right recursion
        merge(num, i, mid, mid + 1, j); //merging of two sorted sub-arrays
        
    }
    
} //end mer_sort

//Implement merge()

void merge(int num[],int i1,int j1,int i2,int j2)
{
    int temp[SIZE]; //array used for merging
    int i, j, k;
    i = i1; //beginning of the first list
    j = i2; //beginning of the second list
    k = 0;
    
    while(i <= j1 && j <= j2) //while elements in both lists
    {
        if(num[i] < num[j])
        {
            temp[k++] = num[i++];
            
        }
        else
        {
            temp[k++] = num[j++];
            
        } //end if
        
    } //end while
    
    while(i <= j1) //copy remaining elements of the first list
    {
        temp[k++] = num[i++];
        
    }
    
    while(j <= j2) //copy remaining elements of the second list
    {
        temp[k++] = num[j++];
        
    }
    
    //Transfer elements from temp[] back to a[]
    
    for(i = i1,j = 0;i <= j2; i++, j++)
    {
        num[i] = temp[j];
        
    }
    
} //end merge()