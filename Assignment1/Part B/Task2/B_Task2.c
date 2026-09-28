//Code purpose: Elevator simulation

#include <stdio.h>
int main(){     //Main  function start

    int current_floor;
    int requested_value;
    current_floor = 0;

    printf("Enter requested value: ");      //Asks user to enter requested floor number
    scanf("%d",&requested_value);           //Stores entered floor number in requested_value

    char *requested = (requested_value == current_floor) ? "Door opening" : (requested_value < current_floor) ? "Moving down" : "Moving up";    //Compares input value with current floor and sets requested to point towards the correct string
    current_floor = requested_value;    //updates current_fllor to the input value
    printf("%s",requested);     //outputs the string pointed by requested

    return 0;
}       //Main function end