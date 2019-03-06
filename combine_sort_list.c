/*Write an algorithm in C to merge the contents of two
    sorted lists. Assume that both lists are represented
    using arrays. The result array should be sorted. What is
    the running time of your algorithm?
    
    Date: 26/2/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <time.h>
#define SIZE1 5
#define SIZE2 6
#define JOINT 11

//Prototype

int *one(int[]); //list 1 - pass int array, return int array
int *two(int[]); //list 2 - pass int array, return int array
void join(int[], int[], int[]); //joint list - pass int array. return int array
int *sort1(int[]); //sort for list1 - pass int array ,return int array
int *sort2(int[]); //sort for list 2 - pass int array, return int array
int *sort_c(int[]); //sort for combined list - pass int array, return int array

int main()
{
    clock_t begin = clock(); //start clock
    
    int list1[SIZE1];
    int list2[SIZE2];
    int combine[JOINT];
    
    //Call one()
    
    one(list1);
    
    //Call two()
    
    two(list2);
    
    //Call join()
    
    join(list1, list2, combine);
    
    clock_t end = clock(); //end clock
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("\n\n Work took %f", time_spent);
    
    flushall(); //borland
    getchar(); //borland
    return 0;
    
} //end main()

//Implement one()

int *one(int list1[])
{
    int i;
    
    //Initialise list1
    
    printf("\n Enter %d numbers\n", SIZE1);
    
    for(i = 0; i < SIZE1; i++)
    {
        printf(" - ");
        scanf("%d", &*(list1 + i));
        
    } //end for
    
    sort1(list1);
    
    printf("\n Sorted list 1: ");
    
    for(i = 0; i < SIZE1; i++)
    {
        printf(" %d ", *(list1 + i));
    
    } //end for
    
    printf("\n");
    
    return list1;
    
} //end one()

//Implement two()

int *two(int list2[])
{
    int i;
    
    //Initialise list2
    
    printf("\n Enter %d numbers\n", SIZE2);
    
    for(i = 0; i < SIZE2; i++)
    {
        printf(" - ");
        scanf("%d", &*(list2 + i));
        
    } //end for
    
    //Call sort()
    
    sort2(list2);
    
    printf("\n Sorted list 2: ");
    
    for(i = 0; i < SIZE2; i++)
    {
        printf(" %d ", *(list2 + i));
    
    } //end for
    
    printf("\n");
    
    return list2;
    
} //end two()

//Implement join()

void join(int list1[], int list2[], int combine[])
{
    int i, j;
    
    for(i = 0; i < SIZE1; i++)
    {
        *(combine + i) = *(list1 + i);
        
    } //end for
    
    for(j = i; j < JOINT; j++)
    {
        *(combine + j) = *(list2 + j - SIZE1);
        
    } //end for
    
    //Display unsorted joint array
    
    printf("\n Combined list before sort: ");
    
    for(i = 0; i < JOINT; i++)
    {
        printf(" %d ", *(combine + i));
        
    } //end for
    
    sort_c(combine);
    
    //Display sorted  joint array
    
    printf("\n\n Combined list after sort: ");

    for(i = 0; i < JOINT; i++)
    {
        printf(" %d ", *(combine + i));
        
    } //end for
    
} //end join()

//Implement sort2()

int *sort2(int srt[])
{
    int i, j;
    int swap;
    int min;
    
    //Selection sort - efficient
    
    for(i = 0; i < (SIZE2 - 1); i++) //last element list1[5] - no need to check because it's last and biggest
    {
        //current minimum (starting point) - left to right
        min = i; //Set minimum position to index
        //minimum position will move with i 
        
        for(j = i + 1; j < SIZE2; j++)
        {
            //check all the elements of the array if any are bigger than minimum
            
            if(*(srt + min) > *(srt + j))
            {
                //Switch minimum position if other array element is bigger than current minimum
                min = j;
                //continue to check other elements after (if any)
                
            } //end if
            
        } //end inner for 
        
        //if the current minimum position is not at original minimum position  
        
        if(min != i)
        {
            //swap contents of lot_num[i] with lot_num[min] - direct switching of contents with  lot_num[i] regardless of position in array
            swap = *(srt + i);
            *(srt + i) = *(srt + min);
            *(srt + min) = swap;
            
        } //end if
        
    } //end outer for
    
    return srt;
    
} //end sort2()

//Implement sort1()

int *sort1(int srt[])
{
    int i, j;
    int swap;
    int min;
    
    //Selection sort - efficient
    
    for(i = 0; i < (SIZE1 - 1); i++) //last element list1[5] - no need to check because it's last and biggest
    {
        //current minimum (starting point) - left to right
        min = i; //Set minimum position to index
        //minimum position will move with i 
        
        for(j = i + 1; j < SIZE1; j++)
        {
            //check all the elements of the array if any are bigger than minimum
            
            if(*(srt + min) > *(srt + j))
            {
                //Switch minimum position if other array element is bigger than current minimum
                min = j;
                //continue to check other elements after (if any)
                
            } //end if
            
        } //end inner for 
        
        //if the current minimum position is not at original minimum position  
        
        if(min != i)
        {
            //swap contents of lot_num[i] with lot_num[min] - direct switching of contents with  lot_num[i] regardless of position in array
            swap = *(srt + i);
            *(srt + i) = *(srt + min);
            *(srt + min) = swap;
            
        } //end if
        
    } //end outer for
    
    return srt;
    
} //end sort1()

//Implement sort_c

int *sort_c(int srt[])
{
    int i, j;
    int swap;
    int min;
    
    //Selection sort - efficient
    
    for(i = 0; i < (JOINT - 1); i++) //last element list1[11] - no need to check because it's last and biggest
    {
        //current minimum (starting point) - left to right
        min = i; //Set minimum position to index
        //minimum position will move with i 
        
        for(j = i + 1; j < JOINT; j++)
        {
            //check all the elements of the array if any are bigger than minimum
            
            if(*(srt + min) > *(srt + j))
            {
                //Switch minimum position if other array element is bigger than current minimum
                min = j;
                //continue to check other elements after (if any)
                
            } //end if
            
        } //end inner for 
        
        //if the current minimum position is not at original minimum position  
        
        if(min != i)
        {
            //swap contents of lot_num[i] with lot_num[min] - direct switching of contents with  lot_num[i] regardless of position in array
            swap = *(srt + i);
            *(srt + i) = *(srt + min);
            *(srt + min) = swap;
            
        } //end if
        
    } //end outer for
    
    return srt;
    
} //end sort()
