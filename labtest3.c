/*Program that uses functions to convert 3 values into Euro or Dollar 
    and displays their average

    Date: 22/2/18
    Author: Louis Chavez
*/

#include <stdio.h>
#define SIZE 3
#define EU 1.19
#define US 0.84

//Prototype 

float change_to_Euro(float[]); //convert dollar to euro 
float change_to_Dollar(float[]); //convert euro to dollar
char terminate(void); //Exit program

int main()
{
    float to_Euro[SIZE];
    float to_USD[SIZE];
    char options;
    float avg_Euro;
    float avg_USD;
    int i;
    char exit;
    
    //Do while loop for menu - guaranteed first go
    
    do
    {
        printf("\n **Currency Convert** \n");
        printf("\n Enter '1' to convert USD to Euro \n");
        printf(" Enter '2' to convert Euro to USD \n");
        printf(" Enter '3' to exit\n");
        printf(" - ");
        
        scanf("%1s", &options);
        
        //switch for options
        
        switch(options)
        {
            case '1':
            {
                printf("\n Enter %d amounts to convert to Euro\n", SIZE);
                
                //initialise array
                
                for(i = 0; i < SIZE; i++)
                {
                    printf(" - ");
                    scanf("%f", &to_Euro[i]);
                    
                } //end for
                
                //Call function
                
                avg_Euro = change_to_Euro(to_Euro);
                
                printf("\n Average in USD: %.1f\n", avg_Euro);
                
                break; //break out of 
                
            } //end case 1
            
            case '2':
            {
                printf("\n Enter %d amounts to convert to US Dollar\n", SIZE);
                
                //initialise array
                
                for(i = 0; i < SIZE; i++)
                {
                    printf(" - ");
                    scanf("%f", &to_USD[i]);
                    
                } //end for
                
                //Call function
                
                avg_USD = change_to_Dollar(to_USD);
                
                printf("\n Average in USD: %.1f\n", avg_USD);
                
                break;
                
            } //end case 2
            
            case '3':
            {
                exit = terminate();
                
                if(exit == 'y')
                {
                    return 0;
                    
                } //end if
                
                break;
                
            } //end case 3
            
            default:
            {
                printf("\n Error: Invalid option selected\n");
                
                break;
                
            } //end default
            
        } //end switch
        
    } //end do 
    while(true);
    
} //end main()

//Implement change_to_Euro()

float change_to_Euro(float conv_Euro[])
{
    int i;
    float sum = 0;
    float USD_EU;
    float EU_average;
    
    for(i = 0; i < SIZE; i++)
    {
        printf("\n Dollar: %.1f  ", conv_Euro[i]);
        //Use formula to calculate Euro
        USD_EU = conv_Euro[i] * US;
        printf("Euro: %.1f \n", USD_EU);
        sum = sum + conv_Euro[i];
        
    } //end for
    
    EU_average = sum / SIZE;
    
    return EU_average;
    
} //end change_to_Euro()

//Implement change_to_Dollar()

float change_to_Dollar(float conv_USD[])
{
    int i;
    float sum = 0;
    float EU_USD;
    float USD_average;
    
    for(i = 0; i < SIZE; i++)
    {
        printf("\n Euro: %.1f  ", conv_USD[i]);
        //Use formula to calculate Dollar
        EU_USD = conv_USD[i] * EU;
        printf("Dollar: %.1f \n", EU_USD);
        sum = sum + conv_USD[i];
        
    } //end for
    
    USD_average = sum / SIZE;
    
    return USD_average;
    
} //end change_to_Dollar()

//Implement terminate()

char terminate(void)
{
    char confirm;
    
    while(confirm != 'n')
    {
        printf("\n Are you sure you want to exit?\n y or n\n - ");
        scanf("%1s", &confirm);
        
        if(confirm == 'y')
        {
            break;
            
        } //end if
        else 
        {
            if(confirm != 'n')
            {
                printf("\n Lobsters for Jae\n");
            
            } //end if
            
        } //end else
        
    } //end while
    
    return confirm;

} //end terminate()
