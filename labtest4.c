/*Lab Test - Program that uses structures and functions to enter driver's licence information from standard input 
                    and display them to standard output

    Date: 12/4/18
    Author: Louis Chavez
*/

#include <stdio.h>

#define K 21
#define N 11

struct date_of_birth
{
    int day;
    int month;
    int year;
    
}; //end date_of_birth

struct info
{
    char firstname[K];
    char surname[K];
    struct date_of_birth dob; //nested structure
    int height;
    int weight;
    char eye_col[N];
    
}; //end info

//Function prototypes

//b - Function to input driver details from standard input
void input(struct info *); //pass by reference - passing info structure pointer (change and keep values) - no return value
    
//c - Function to display entered details to standard output
void dsp(struct info); //pass by value - passing info structure - no return value

int main()
{
    //b - create variables for two separate people
    struct info driver1, driver2;
    
    //Call input() - input information of driver
    
    input(&driver1); //passing address of variable '&'
    input(&driver2);
    
    //c
    //Call dsp() - display entered information
    
    dsp(driver1);
    dsp(driver2);
    
    getchar(); //borland
    return 0;
    
} //end main

//Implement input(): Function to input details of driver from standard input - no return value

void input(struct info * driver)
{
    static int num = 0; //counter for display purposes only - static allows variable to keep value
    
    num++; //increment num for every entry
    
    printf("\n\t Driver #%d\n", num);
    
    //prompt firstname
    printf("\n Enter Firstname:\n - ");
    gets((*driver).firstname); //allows for wide space characters
    
    //prompt surname
    printf("\n Enter Surname:\n - ");
    gets((*driver).surname);
    
    //prompt date of birth
    printf("\n Enter Date of Birth:\n dd - ");
    scanf("%d", &(*driver).dob.day);
    printf(" mm - ");
    scanf("%d", &(*driver).dob.month);
    printf(" yyyy - ");
    scanf("%d", &(*driver).dob.year);
    
    //prompt height
    printf("\n Enter Height (cm):\n - ");
    scanf("%d", &(*driver).height);
    
    //prompt weight
    printf("\n Enter Weight (kg):\n - ");
    scanf("%d", &(*driver).weight);
    
    //prompt eye colour
    printf("\n Enter Eye Colour:\n - ");
    scanf("%s", &(*driver).eye_col); //no wide space 
    
    flushall(); //clear input stream
    
} //end input()

//Implement dsp(): Function to display details entered onto standard output - no return value

void dsp(struct info driver)
{
    static int num = 0; //static int counter for display purposes only - keeps value in function
    
    num++; //increment num for every entry 
    
    printf("\n\t Driver #%d\n", num);
    printf("\n Firstname: %s\n", driver.firstname);
    printf(" Surname: %s\n", driver.surname);
    printf(" DOB: %d/%d/%d\n", driver.dob.day, driver.dob.month, driver.dob.year);
    printf(" Height: %d cm\n", driver.height);
    printf(" Weight: %d kg\n", driver.weight);
    printf(" Eye Colour: %s\n", driver.eye_col);
    
} //end dsp()
