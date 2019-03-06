/*Program description: Maths Quiz
    Date: 25/10/17
    Author: Louis Chavez
*/

#include <stdio.h>

int main()
{
    //Operation1 display menu & enter options
    
    int options;
    int rounds;
    int answer;
    int correct1, correct2, correct3, correct4, correct5;
    int right; // variable to record number of right qs
    int wrong; //variable to record number of wrong qs
    int counter; //variable to record number of quiz attempts 
    
    correct1 = 19;
    correct2 = 100;
    correct3 = 2;
    correct4 = 25;
    correct5 = 42;
    rounds = 0;
    right = 0;
    wrong = 0;
    counter = 0;
    
    //do while loop to display menu - ensure menu is at least displayed once
    
    printf("\n ~ LET'S PLAY A MATHS GAME ~\n");
    
    do
    {
        printf("\n MENU: Choose Options 1-4\n");
        printf("\n 1. Select Rounds\n");
        printf("\n 2. Start Quiz\n");
        printf("\n 3. Display Results\n");
        printf("\n 4. Exit Game\n\n");
        printf(" - ");
        
        //prompt for options using scanf
        
        scanf("%d", &options);
        
        //switch case for each option in menu - more efficient than if
        
        switch(options)
        {
            case 1: //Option 1 How many rounds
            {
                rounds = 0; //incase user changes their mind or after every round, re-initialise rounds to 0
                right = 0; //re-initialise right counter after every try
                wrong = 0; //re-initialise wrong counter after every try
                counter = 0; //re-initialise variable after every try
                
                 do
                {
                    printf("\n ~ How many rounds would you like to play? (min 1 & max 5) ~ \n\n");
                    printf(" [Enter 0 to exit to menu] \n\n");
                    printf(" - ");
                
                    //prompt for rounds using scanf
                
                    scanf("%d", &rounds); //rounds will be initialised by user
                    
                    //if rounds is less than 1 or more that 5 - display error message - else print rounds selcted
                
                    if(rounds < 0 || rounds > 5) 
                    {
                        printf("\n **Error: Please select a number between 0-5**\n\n");
                    
                    } //end if
                    else
                    {
                        if(rounds == 0)
                        {
                            break;
                            
                        } //end if
                        else
                        {
                            if(rounds == 1)
                            {
                                printf("\n ~ %d round selected ~\n", rounds);
                        
                            } //end if
                            else
                            {
                            printf("\n ~ %d rounds selected ~\n", rounds);
                        
                            } //end else
                        
                        }// end else
                    
                    } //end else
                    
                }
                while(rounds < 1 || rounds > 5); //while rounds is less than 1 or more than 5 - repeat the question - error checking
                
                break; //get out of switch - back to menu
                
            } //end Option 1
            
            //Operation2 Quiz
            
            case 2: //Option 2 Start Quiz
            {
                if(rounds == 0) //if rounds is equal to 0 - display error message, do option 1 first - error checking
                {
                    printf("\n **Error: 0 rounds selected - Execute option 1 first**\n\n");
                    
                    break; //back to menu
                
                } //end if
                
                right = 0; //re-initialise right counter incase of retry
                wrong = 0; //re-initialise wrong counter incase of retry
                counter = 0; //re-initialise variable after incase of retry
                
                counter++; //+1 increment counter added for each attempt 
                        
                printf("\n ~ QUIZ START ~\n");
                printf("\n 9 + 10 = ?\n\n");
                printf(" Answer: ");
                
                //prompt for answer using scanf
                
                scanf("%d", &answer);
                
                //if else statement to display right or wrong answer
                
                if(answer != correct1) //if answer is not equal to variable - diplay that answer is wrong else answer is right
                {
                    printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct1);
                    wrong++; //+1 increment to record wrong questions amount
                            
                } //end if
                else
                {
                    printf("\n You entered: %d - Correct!\n\n", answer, correct1);
                    right++; //+1 increment to record right questions amount
                            
                } //end else
                
                //switch statement for rounds more that 1
                
                switch(rounds)
                {
                    case 2: //2 rounds selected
                    {
                        printf("\n 60 + 40 = ?\n\n");
                        printf(" Answer: ");
                        
                        scanf("%d", &answer);
                        
                        if(answer != correct2)
                        {
                            printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct2);
                            wrong++;
                            
                        } //end if
                        else
                        {
                            printf("\n You entered: %d - Correct!\n\n", answer, correct2);
                            right++;
                            
                        } //end else
                        
                        break;
                        
                    } //end case 2
                    
                    case 3: //3 rounds selected 
                    {
                        printf("\n 60 + 40 = ?\n\n");
                        printf(" Answer: ");
                        
                        scanf("%d", &answer);
                        
                        if(answer != correct2)
                        {
                            printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct2);
                            wrong++;
                            
                        } //end if
                        else
                        {
                            printf("\n You entered: %d - Correct!\n\n", answer, correct2);
                            right++;
                            
                        } //end else 
                        
                        printf("\n 4 / 2 = ?\n\n");
                        printf(" Answer: ");
                        
                        scanf("%d", &answer);
                        
                         if(answer != correct3)
                        {
                            printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct3);
                            wrong++;
                            
                        } //end if
                        else
                        {
                            printf("\n You entered: %d - Correct!\n\n", answer, correct3);
                            right++;
                            
                        } //end else
                        
                        break;
                        
                    } //end case 3
                    
                    case 4: //4 rounds selected
                    {
                        printf("\n 60 + 40 = ?\n\n");
                        printf(" Answer: ");
                        
                        scanf("%d", &answer);
                        
                        if(answer != correct2)
                        {
                            printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct2);
                            wrong++;
                            
                        } //end if
                        else
                        {
                            printf("\n You entered: %d - Correct!\n\n", answer, correct2);
                            right++;
                            
                        } //end else 
                        
                        printf("\n 4 / 2 = ?\n\n");
                        printf(" Answer: ");
                        
                        scanf("%d", &answer);
                        
                         if(answer != correct3)
                        {
                            printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct3);
                            wrong++;
                            
                        } //end if
                        else
                        {
                            printf("\n You entered: %d - Correct!\n\n", answer, correct3);
                            right++;
                            
                        } //end else
                        
                        printf("\n 5 * 5 = ?\n\n");
                        printf(" Answer: ");
                        
                        scanf("%d", &answer);
                        
                         if(answer != correct4)
                        {
                            printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct4);
                            wrong++;
                            
                        } //end if
                        else
                        {
                            printf("\n You entered: %d - Correct!\n\n", answer, correct4);
                            right++;
                            
                        } //end else
                        
                        break;
                        
                    } //end case 4
                    
                    case 5: //5 rounds selected
                    {
                        printf("\n 60 + 40 = ?\n\n");
                        printf(" Answer: ");
                        
                        scanf("%d", &answer);
                        
                        if(answer != correct2)
                        {
                            printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct2);
                            wrong++;
                            
                        } //end if
                        else
                        {
                            printf("\n You entered: %d - Correct!\n\n", answer, correct2);
                            right++;
                            
                        } //end else 
                        
                        printf("\n 4 / 2 = ?\n\n");
                        printf(" Answer: ");
                        
                        scanf("%d", &answer);
                        
                         if(answer != correct3)
                        {
                            printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct3);
                            wrong++;
                            
                        } //end if
                        else
                        {
                            printf("\n You entered: %d - Correct!\n\n", answer, correct3);
                            right++;
                            
                        } //end else
                        
                        printf("\n 5 * 5 = ?\n\n");
                        printf(" Answer: ");
                        
                        scanf("%d", &answer);
                        
                         if(answer != correct4)
                        {
                            printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct4);
                            wrong++;
                            
                        } //end if
                        else
                        {
                            printf("\n You entered: %d - Correct!\n\n", answer, correct4);
                            right++;
                            
                        } //end else
                        
                        printf("\n 30 + 12 = ?\n\n");
                        printf(" Answer: ");
                        
                        scanf("%d", &answer);
                        
                          if(answer != correct5)
                        {
                            printf("\n You entered: %d - Incorrect! The correct answer is %d\n\n", answer, correct5);
                            wrong++;
                            
                        } //end if
                        else
                        {
                            printf("\n You entered: %d - Correct!\n\n", answer, correct5);
                            right++;
                            
                        } //end else
                        
                        break;
                        
                    } //end case 5
                    
                } //end switch rounds
                
                break; //return to main menu
                
            } //end Option 2
            
            //Operation3 Results
            
            case 3://Option 3 Display Results
            {
                //if quiz not selected but rounds selected - error
                
                if(counter == 0 && rounds != 0)
                {
                    printf("\n **Error: Quiz has not been completed - Execute option 2 first**\n\n");
                    
                    break; 
                    
                } //end if
                
                //if no rounds selected - error
                
                if(rounds == 0)
                {
                    printf("\n **Error: No rounds selected - Execute option 1 first**\n\n");
                    
                    break;
                
                } //end if
                
                //if quiz is done 
                
                if(counter == 1 && rounds > 0)
                {
                    printf("\n RESULTS: \n");
                    printf("\n ~ You got %d/%d questions correct! ~\n\n", right, rounds);
                    printf("\n ~ You got %d/%d questions incorrect! ~\n\n", wrong, rounds);
                    
                    break;
                    
                } //end if
                
            } //end Option 3
            
            //Displau error if invalid options input
            
            default:
            {
                printf("\n **Error: Invalid option - Please select options 1-4**\n\n");
                break;
                
            } //end default
        
        } //end switch
        
    } //end do
    while(options != 4); //game runs  from options 1-3 & terminates with option 4
    
    flushall(); //exe won't close
    return 0;
    
} //end main()