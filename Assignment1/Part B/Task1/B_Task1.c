/*Code written by: Moosa Baig 26K-0010
File Name: B_Task1.c
Code purpose: Calculates the hotel night stays based on multiple factors
*/
#include <stdio.h>
int main(){

    int season;
    int room_type;
    int nights;
    float total_price;
    int price;

    price = 0;
    nights= 0;

    printf("Enter Season: \n");     //Enter Season type
    printf("1- Peak \n2- Off-Peak \n: ");
    scanf("%d",&season);            //Input season

    printf("Enter room type: \n");  //Enter room type
    printf("1- Standard \n2- Deluxe \n3- Suite \n: ");
    scanf("%d",&room_type);         //Input room type

    printf("Enter number of night stays: "); //Enter nights
    scanf("%d", &nights);            //Input number of night stays

    switch (season)                 //Check condition based on season type
    {
    case 1:                         //Peak season chosen
        switch (room_type)          //Check condition based on room type
        {
        case 1:
            price = 5000;           //Set price to 5000 when room type is Standard
            break;
        case 2:
            price = 8000;           //Set price to 8000 when room type is Deluxe
            break;
        case 3:
            price = 12000;          //Set price to 12000 when room type is Suite
            break;
        
        default:
            printf("Invalid value entered. Defaulting values to 0 \n");
            break;
        }
        break;
    case 2:                         //Off-Peak season chosem
        switch (room_type)          //Check condition based on room type
        {
        case 1:
            price = 3000;           //Set price to 3000 when room type is Standard
            break;
        case 2:
            price = 5000;           //Set price to 5000 when room type is Deluxe
            break;
        case 3:
            price = 8000;          //Set price to 8000 when room type is Suite
            break;
        
        default:
            printf("Invalid value entered. Defaulting values to 0 \n");
            break;
        }    

    default:
        printf("Invalid value entered. Defaulting values to 0 \n");
        break;
    }

    total_price = price * nights;
    if (nights > 7)                             //Applies 15% discount if night stays exceed 7 
        total_price = total_price * 0.85;
    
    printf("Total price is %.2f",total_price); //Output final calculated price

    return 0; //End of main functiom

}