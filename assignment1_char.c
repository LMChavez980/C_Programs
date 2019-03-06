/*Program description: Maths Quiz
    Date: 25/10/17
    Author: Louis Chavez
*/

#include <stdio.h>

int main()
{
    //Operation1 display menu & enter options
    
    char options; //avoid infinte loops
    char roundsC; //avoid infinite loops
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
        
        scanf("%1s", &options);
        
        //switch statement for specific options
        
        switch(options)
        {
            case '1': //Option 1 How many rounds
            {
                rounds = 0; //incase user changes their mind or after every round, re-initialise rounds to 0
                right = 0; //re-initialise right counter after every rounds selection
                wrong = 0; //re-initialise wrong counter after every rounds selection
                counter = 0; //re-initialise quiz counter after every rounds selection
                
                do
                {
                    printf("\n ~ How many rounds would you like to play? (min 1 & max 5) ~ \n\n");
                    printf(" [Enter 0 to exit to menu] \n\n");
                    printf(" - ");
                
                    //prompt for rounds using scanf
                
                    scanf("%1s", &roundsC); //rounds will be initialised by user
                    
                    switch(roundsC)
                    {
                        case '0': 
                        {
                            break; //exit to menu
                        
                        } //end case '0'
                       
                        case '1':
                        {
                            rounds = 1;
                            printf("\n ~ %d round selected ~\n", rounds);
                            break;
                            
                        } //end case '1'
                        
                        case '2':
                        {
                            rounds = 2;
                            printf("\n ~ %d round selected ~\n", rounds);
                            break;
                            
                        } //end case '2'
                        
                        case '3':
                        {
                            rounds = 3;
                            printf("\n ~ %d round selected ~\n", rounds);
                            break;
                            
                        } //end case '3'
                        
                        case '4':
                        { 
                            rounds = 4;
                            printf("\n ~ %d round selected ~\n", rounds);
                            break;
                            
                        } //end case '4'
                        
                        case '5':
                        {
                            rounds = 5;
                            printf("\n ~ %d round selected ~\n", rounds);
                            break;
                            
                        } //end case '5'
                        
                        //Display error if 0-5 is not entered
                        
                        default:
                        {
                            printf("\n **Error: Please select a number between 0-5**\n\n");
                            break;
                            
                        } //end default
                        
                    } //end switch
                    
                }
                while(roundsC != '0' && roundsC != '1' && roundsC != '2' && roundsC != '3' && roundsC != '4' && roundsC != '5'); //while rounds is not an available option - repeat the question - error checking
                
                break; //back to main menu
                
            } //end Option 1
            
            //Operation2 Quiz
            
            case '2': //Option 2 Start Quiz
            {
                //Display error and return to menu if no rounds selcted
                
                if(rounds == 0)
                {
                    printf("\n **Error: 0 rounds selected - Execute option 1 first**\n\n");
                    
                    break; //back to menu
                    
                } //end if
                    
                right = 0; //re-initialise right counter incase of retry
                wrong = 0; //re-initialise wrong counter incase of retry
                counter = 0; //re-initialise variable after incase of retry
                
                counter++; //+1 increment counter added for each attempt of quiz
                        
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
                
                //switch statement for each round more than 1
                
                switch(rounds) //switch case - specific to how many rounds selected
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
                
                break;
                
            } //end Option 2
            
            //Operation3 Results
            
            case '3'://Option 3 Display Results
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
                
                //if quiz is done - while loop to include exit error
                
                if(counter == 1 && rounds > 0)
                {
                    printf("\n RESULTS: \n");
                    printf("\n ~ You got %d/%d questions correct! ~\n\n", right, rounds);
                    printf("\n ~ You got %d/%d questions incorrect! ~\n\n", wrong, rounds);
                    
                    break;
                    
                } //end if
                
            } //end Option 3
            
            //Display error message for invalid option
            
            default:
            {
                printf("\n **Error: Invalid option selected - Please select a number beween 1 and 4**\n\n");
                break;
                
            } //end default
            
        } //end switch
        
    } //end do
    while(options != '4'); //game runs from options 1-3 & terminates with option 4
    
    flushall();//exe won't close
    return 0;
    
} //end main()