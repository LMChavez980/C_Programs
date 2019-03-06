/*Lotto game program that uses functions to:
    
    1. Enter any 6 numbers (1–42 inclusive) from the keyboard. Perform any
        necessary validation (error-checking) required (e.g. all numbers must be
        different, range 1-42, etc.).

    2. Display the contents of the 1-D array containing your lotto numbers that you
        entered.
    
    3. Sort the contents of the array in increasing order (i.e. 1st element = smallest
        number, 2nd element = 2nd smallest number, etc.). You may use any sorting
        algorithm of your choice.
    
    4. Compare your chosen lotto numbers in the 1-D array with the following
        winning numbers:
        1,3,5,7,9,11 (Winning numbers), 42 (Bonus number)
        Depending on how many of your chosen numbers match the above winning numbers,
        your program should display one of the following messages: 
        Match 6: Jackpot
        Match 5 + Bonus: New car
        Match 5: Holiday
        Match 4 + Bonus: Weekend away
        Match 4: Night out
        Match 3 + Bonus: Cinema ticket

    5. Display the frequency of the numbers entered each time the user enters a new
        set of numbers (without exiting the program) on the screen. 

    6. Exit program
    
    Date: 10/3/18
    Author: Louis Chavez
*/

#include <stdio.h>
#include <string.h> //for string functions
#include <conio.h> //clrscr function

#define SIZE 6
#define MIN 1
#define MAX 42
#define FREQ 43
#define OPT 100
#define K 2

//Prototypes

void opt_check(char[],char * [], int[]); //passing char and int arrays, return nothing - pass by reference
void sel(int[], int[]); //1: pass int arrays, return nothing - pass by reference
void disp(int[]); //2: passing array, return nothing - pass by reference 
void sort(int[]); //3: passing int array, returning nothing - pass by reference
void comp(int[]); //4: passing int array, return nothing - pass by reference
void freq(int[], int[]); //5: passing int array, returning nothing - pass by reference
void term(char [], char * [], int[]); //6: passing character, returning nothing - pass by reference

int main()
{
    char option[OPT]; //string for option input
    char * choice[SIZE] = {"1", "2", "3", "4", "5", "6"}; //checking input
    int lot_num[SIZE]; //array for lotto numbers
    int freq_num[FREQ] = {NULL}; //array for number selection frequency - all elements in array are 0
    char * exit_yes[K] = {"yes", "y"}; //exit 
    char exit[OPT]; //string for exit input
    int opt_count = 0; //Track if option 1 has been opened - allows user to go to other optons if so
    int check[SIZE] = {1, 1, 1, 1, 1, 1}; //checking choice[]
    int check_ext[SIZE] = {1, 1}; //check if exit input is valid
    
    //Do while to display menu - guaranteed first loop 
    
    do
    {
        printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n *****LOTTO GAME***** \n");
        printf("\n ~~~~~~~~MENU~~~~~~~~\n");
        printf("\n 1: Enter your lotto numbers\n");
        printf("\n 2: Display your lotto numbers\n");
        printf("\n 3: Sort your lotto numbers (ascending order)\n");
        printf("\n 4: See if you're a winner\n");
        printf("\n 5: Display the frequency of numbers selected\n");
        printf("\n 6: Exit \n");
        printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n - ");
        
        scanf("%s", option);
        
        //Call opt_check() - compare strings if input is valid
        
        opt_check(option, choice, check);
        
        if(*(check + 0) == 0) //Enter numbers into array 
        {
            clrscr(); //clear screen 
            
            opt_count++; //increment count for every option 1 entry
            
            //Call sel()
            
            sel(lot_num, freq_num);
            
        } //end option 1
        
        if(*(check + 1)== 0) //Display numbers entered
        {
            clrscr();
            
            if(opt_count >= MIN) //only allow user if the opt_count is 1 or more than 1
            {
                //Call disp()
                
                disp(lot_num);
                
            } //end if
            else //Error if opt_count is not incremented
            {
                printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
                printf("\n **Error: No lotto numbers selected - Execute option 1 first**\n");
                
            } //end else
            
        } //end option 2
        
        if(*(check + 2) == 0) //Sort numbers in array
        {
            clrscr();
            
            if(opt_count >= MIN)
            {
                //Call sort()
                
                sort(lot_num);
                
            } //end if
            else
            {
                printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
                printf("\n **Error: No lotto numbers selected - Execute option 1 first**\n");
                
            } //end else
            
        } //end option 3
        
        if(*(check + 3) == 0) //Compare numbers with winning numbers
        {
            clrscr();
            
            if(opt_count >= MIN)
            {
                //Call comp()
                
                comp(lot_num);
                
            } //end if
            else
            {
                printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
                printf("\n **Error: No lotto numbers selected - Execute option 1 first**\n");
                
            } //end else
            
        } //end option 4
        
        if(*(check + 4) == 0) //Check frequency of numbers selected
        {
            clrscr();
            
            if(opt_count >= MIN)
            {
                //Call freq()
                
                freq(lot_num, freq_num);
                
            } //end if
            else
            {
                printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
                printf("\n **Error: No lotto numbers selected - Execute option 1 first**\n");
                
            } //end else
            
        } //end option 5
         
        if(*(check + 5) == 0) //Exit program
        {
            clrscr();
            
            //Call term()
            
            term(exit, exit_yes, check_ext);
            
            //if string is valid terminate program
            
            if(*(check_ext + 0) == 0 || *(check_ext + 1) == 0)
            {
                return 0;
                
            } //end if
            else
            {
                clrscr();
                
            } //end else
            
        } //end option 6
        
        //Error check if option input is not valid
        
        if(*(check + 0) != 0 && *(check + 1) != 0 && *(check + 2) != 0 && *(check + 3) != 0 && *(check + 4) != 0 && *(check + 5) != 0)
        {
            clrscr();
            
            printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
            printf("\n **Error: Invalid option selected**\n");
            
        } //end if
        
    }
    while(true); //will continue to loop until user follows exit protocol
    
} //end main()

//Implement opt_check()

void opt_check(char option[], char * choice[], int check[])
{
    int i;
    
    for(i = 0; i < SIZE; i++)
    {
        *(check + i) = strcmp(*(choice + i), option);
        
    } //end for()
    
} //end opt_check()

//1: Implement sel()

void sel(int lot_num[], int fr_num[])
{
    int i, j; //index
    int dup_num[FREQ] = {NULL}; //array to track duplicates 
    
    //Initialise array to 0 - Error checking for character inputs
    
    for(i = 0; i < SIZE; i++)
    {
        *(lot_num + i) = NULL;
        
    } //end for
    
    //Initialise lotto numbers array 
    
    printf("\n ~~~~~~OPTION 1~~~~~~\n");
    printf("\n Enter %d numbers (%d-%d)\n", SIZE, MIN, MAX);
    
    for(i = 0; i < SIZE; i++)
    {
        printf(" - ");
        scanf("%d", &*(lot_num + i));
        
        //Error check - if the number entered is out of range
        
        /*Error check - if user enters a character, the scanf("%d") doesn't recognise the character and ignores the input
                    taking the value inside the array instead. Since the array is initialised to 0, it will say it is out of range
                */
        
        //While the user has not entered a number in range repeat prompt for input
        
        while(*(lot_num + i) > MAX || *(lot_num + i) < MIN)
        {
            flushall(); //clear input stream - so input is not passed
            
            printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
            printf("\n **Error: Invalid Input - numbers %d to %d only**\n", MIN, MAX);
            printf("\n ~~~~~~OPTION 1~~~~~~\n");
            printf("\n Enter %d numbers (%d-%d)\n", SIZE, MIN, MAX);
            printf(" - ");
            scanf("%d", &*(lot_num + i));
            clrscr();
            
        } //end while
        
        //if number entered is in range record frequency 
        
        j = *(lot_num + i);
        
        //Record frequency
        
        if(j >= MIN || j <= MAX)
        {
            (*(dup_num + j))++; //increment duplicates array
            (*(fr_num + j))++; //increment frequency array
            
        } //end if
        
        //if the same number has been entered more than once during number selection - 
        
        if(*(dup_num + j) > MIN)
        {
            printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
            printf("\n **Error: Invalid Input - number already entered**\n");
            (*(dup_num + j))--; //decrement for duplicate tracking 
            (*(fr_num + j))--; //decrement for frequency
            
            i--; //reset number selection for array position
            
        } //end if
        
    } //end for
    
} //end sel_num()

//2: Implement disp()

void disp(int lot_num[])
{
    int i; //index
    
    printf("\n ~~~~~~OPTION 2~~~~~~\n");
    printf("\n Lotto numbers entered:");
    
    //Display contents of array
    
    for(i = 0; i < SIZE; i++)
    {
        printf(" %d ", *(lot_num + i));
    
    } //end for
    
    printf("\n");
    
} //end dis_num()

//3: Implement sort()

void sort(int lot_num[])
{
    int min; //minimum position
    int i, j; //index
    int swap; //temporary variable
    
    printf("\n ~~~~~~OPTION 3~~~~~~\n");
    
    //Selection sort - efficient
    
    for(i = 0; i < (SIZE - MIN); i++) //last element lot_num[SIZE] - no need to check because it's last and biggest
    {
        //current minimum (starting point) - left to right
        min = i; //Set minimum position to index
        //minimum position will move with i 
        
        for(j = i + MIN; j < SIZE; j++)
        {
            //check all the elements of the array if any are bigger than minimum
            
            if(*(lot_num + min) > *(lot_num + j))
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
            swap = *(lot_num + i);
            *(lot_num + i) = *(lot_num + min);
            *(lot_num + min) = swap;
            
        } //end if
        
    } //end outer for
    
    //Display sorted numbers
    
    printf("\n Sorted lotto numbers: ");
    
    for(i = 0; i < SIZE; i++)
    {
        printf(" %d ", *(lot_num + i));
    
    } //end for
    
    printf("\n");
    
} //end sort_num()

//4: Implement comp()

void comp(int lot_num[])
{
    int i, j; //index
    int win_num[SIZE] = { 1, 3, 5, 7, 9, 11 }; //Winning numbers
    int match = 0; //counter for matches
    int m_bonus = 0; //counter bonus
    int bonus = 42; //bonus number
    
    //Check with any of the lotery numbers match with any of the winning numbers
    
    for(i = 0; i < SIZE; i++)
    {
        //If lottery number is equal to the bonus
        
        if(*(lot_num + i) == bonus)
        {
            m_bonus++;
            
        } //end if
        
        for(j = 0; j < SIZE; j++)
        {
            if(*(lot_num + i) == *(win_num + j))
            {
                match++;
                
            } //end if
        
        } //end inner for
        
    } //end outer for 
    
    printf("\n ~~~~~~OPTION 4~~~~~~\n");
    
    //If the numbers matched
    
    if(match == 3 && m_bonus == 1)
    {
        printf("\n 3 Matches + Bonus\n\n Conratulations! You won a cinema ticket!\n");
        
    } //end if
    
    if(match == 4 && m_bonus == 0)
    {
        printf("\n 4 Matches\n\n Congratulations! You won a night out!\n");
        
    } //end if
    else
    {
        if(match == 4 && m_bonus == 1)
        {
            printf("\n 4 Matches + Bonus\n\n Congratulations! You won a weekend away!\n");
            
        } //end if
        
    } //end else
    
    if(match == 5 && m_bonus == 0)
    {
        printf("\n 5 Matches\n\n Congratulations! You won a holiday!\n");
        
    }
    else
    {
        if(match == 5 && m_bonus == 1)
        {
            printf("\n 5 Matches + Bonus\n\n Congratulations! You won a new car!\n");
            
        } //end if
        
    } //end else
    
    if(match == 6 && m_bonus == 0)
    {
        printf("\n 6 Matches\n\n Congratulations! You won the jackpot!\n");
        
    } //end if
    
    //if number of matches are out of winning range
    
    if(match <= 3 && m_bonus == 0 || match < 3 && m_bonus == 1)
    {
        printf("\n You are not a winner today. Better luck next time!\n");
        
    } //end if
    
} //end comp_num()

//5: Implement freq()

void freq(int lot_num[], int freq_num[])
{
    int i, j; //index
    
    printf("\n ~~~~~~OPTION 5~~~~~~\n");
    printf("\n Frequency of numbers selected:\n");
    
    //Check if the lotto number is equal to the position of array fr_num - if yes then display contents of array fr_num
    
    for(i = 0; i < SIZE; i++)
    {
        for(j = MIN; j < FREQ; j++)
        {
            if(*(lot_num + i) == j) //access the frequency of the lotto number
            {
                printf("\n %d: %d times\n", *(lot_num + i), *(freq_num + j));
                
                break;
                
            }
            
        } //end outer for
        
    } //end inner for

} //end freq()

//6: Implement term()

void term(char confirm[], char * exit_yes[], int check_yes[])
{
    int check_no[K] = {1, 1}; //array for value of comparing strings
    int i; //index
    char * exit_no[K] = {"no", "n"}; //array for "no" input
    
    printf("\n ~~~~~~OPTION 6~~~~~~\n");
    
    //Keep asking in case of errors
    
    do
    {
        printf("\n Are you sure you want to exit?\n y (yes) or n (no)\n - ");
        scanf("%s", confirm);
        
        clrscr();
        
        //check input if valid
    
        for(i = 0; i < K; i++)
        {
            *(check_no + i) = strcmp(*(exit_no + i), confirm);
            *(check_yes + i) = strcmp(*(exit_yes + i), confirm);
            
        } //end for
        
        //if input is correct  return to main
        
        if(*(check_yes + 0) == 0 || *(check_yes + 1) == 0|| *(check_no + 0) == 0 || *(check_no + 1) == 0)
        {
            break;
            
        } //end if
        
        //else - error message
        
        printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n **Error: Invalid input - Enter y (yes) or n (no) \n");
        printf("\n ~~~~~~~~~~~~~~~~~~~~\n");
        
    }
    while(true);

} //end term()
