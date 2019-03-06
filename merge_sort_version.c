/*Write an algorithm in C to merge the contents of two
    sorted lists. Assume that both lists are represented
    using arrays. The result array should be sorted. What is
    the running time of your algorithm?
    
    Date: 26/2/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <time.h>
#define JOINT 11

//Prototype

void mergesort(int[], int, int); //
void merge(int[], int, int, int, int);


int main()
{
    clock_t begin = clock(); //start clock
    
    int combine[JOINT];
    int i;
    
    //Initialise array
    
    printf("\n Enter %d numbers\n", JOINT);
    
    for(i = 0; i < JOINT; i++)
    {
        printf(" - ");
        scanf("%d", &*(combine + i));
        
    } //end for

    //Call mergesort()
    
    mergesort(combine, 0, JOINT-1);
    
    printf("\n\n Sorted array:");
    
    for(i = 0; i < JOINT; i++)
    {
        printf(" %d ",combine[i]);
        
    }
    
    clock_t end = clock(); //end clock
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("\n\n Work took %f", time_spent);
    
    flushall(); //borland
    getchar(); //borland
    return 0;
    
} //end main()

//Implement mergesort()

void mergesort(int combine[],int i,int j)
{
    int mid;

    if(i < j)
    {
        mid = (i + j) / 2;
        mergesort(combine, i, mid); //left recursion
        mergesort(combine, mid + 1, j); //right recursion
        merge(combine, i, mid, mid+1, j); //merging of two sorted sub-arrays
        
    }

} //end mergesort()

//Implement merge()

void merge(int combine[],int i1,int j1,int i2,int j2)
{
    int temp[50];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    
    while(i <= j1 && j <= j2)    //while elements in both lists
    {
        if(combine[i] < combine[j])
        {
            temp[k++] = combine[i++];
            
        }
        else
        {
            temp[k++] = combine[j++];
            
        }
        
    }
    
    while(i <= j1) //copy remaining elements of the first list
    {
        temp[k++] = combine[i++];
        
    }

    while(j <= j2) //copy remaining elements of the second list
    {
        temp[k++] = combine[j++];
        
    }
    
    //Transfer elements from temp[] back to a[]
    
    for(i = i1, j = 0; i <= j2; i++, j++)
    {
        combine[i] = temp[j];
        
    }
}