#include <stdio.h>
#include <stdbool.h>

int main(){
    int rows = 0;   //It will be assumed user enters values which having a starting point from 1
    int cols = 0;


    //Input seating plan
    printf("Enter number of Rows in cinema: ");
    scanf("%d", &rows);

    printf("Enter number of seats per row: ");
    scanf("%d", &cols);

    int theatre[rows][cols];

    //Input current status of every seat
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            printf("Enter status of seat %d, row %d (Enter 1 if seat booked, enter 0 if seat empty): ", col, row);

            scanf("%d",&theatre[row][col]);
            while(theatre[row][col] != 0 && theatre[row][col] != 1){
                printf("Enter a valid number!: ");
                scanf("%d",&theatre[row][col]);
            }
        }
    }

    //Display seating arrangment
    for(int x = 0; x < rows; x++){
        printf("Row %d:\t", x);
        for(int y = 0; y < cols; y++){
            if(theatre[x][y] == 0)
                  printf("_  ");
            else{
                printf("X  ");
            }
        }
        printf("\n");
    }
    printf("\n \nTotal number of seats: %d\n", rows*cols);

    //Seat availabilty
    int rowFreeCount = 0;
    int totalFreeCount = 0;

    printf("\nSeats available in\n");
    for(int x = 0; x < rows; x++){
        for(int y = 0; y < cols; y++){

            if(theatre[x][y] == 0){
                rowFreeCount = rowFreeCount + 1;
            }
        }
        printf("Row: %d: %d\n",x,rowFreeCount);
        totalFreeCount = totalFreeCount + rowFreeCount;
        rowFreeCount = 0;
    }

    printf("\nTotal number of available seats: %d", totalFreeCount);
    totalFreeCount = 0;

    //Group booking
    int bookingPeople = 0;      //Stores number of people required for booking
    int middleRow = rows/2;
    int targetRow = 0;
    int startSeat = 0;
    bool spaceFound = false;

    printf("\n\nEnter total number of people for group booking: ");
    scanf("%d", &bookingPeople);

    while(bookingPeople <= 0 || bookingPeople > cols){
        printf("Value entered is either less than 1 or group size exceeds number of seats in row. pls enter again: ");
        scanf("%d", &bookingPeople);
    }

    for(int x = 0; x < rows; x++){
        int rLess = middleRow - x;
        int rMore = middleRow + x;

        if(rLess>= 0 && rLess < rows){
            int consCount = 0;
            for(int col = 0; col< cols; col++){
                if (theatre[rLess][col] == 0){
                    consCount = consCount + 1;

                    if(consCount == bookingPeople){
                        targetRow = rLess;
                        startSeat = col - bookingPeople + 1;
                        spaceFound = true;
                        break;
                    }
                }
                else{
                    consCount = 0;
                }
                if(spaceFound) break;
            }
        }

        if(x> 0 && rMore >= 0 && rMore < rows){
            int consCount = 0;
            for(int col = 0; col< cols; col++){
                if (theatre[rMore][col] == 0){
                    consCount = consCount + 1;

                    if(consCount == bookingPeople){
                        targetRow = rMore;
                        startSeat = col - bookingPeople + 1;
                        spaceFound = true;
                        break;
                    }
                }
                    else{
                consCount = 0;
                }
                if(spaceFound) break;
            }
        }
    }

    if(spaceFound){
        for(int x = startSeat; x < startSeat + bookingPeople; x++){
            theatre[targetRow][x] = 1;
        }
        printf("\nGroup of %d seated in Row %d, Seats %d to %d\n\n", bookingPeople, targetRow, startSeat, startSeat + bookingPeople - 1);

        printf("Updated seating arrangement: \n");
        for(int x = 0; x < rows; x++){
            printf("Row %d:\t", x);
            for(int y = 0; y < cols; y++){
                if(theatre[x][y] == 0)
                      printf("_  ");
                else{
                    printf("X  ");
                }
            }
            printf("\n");
        }
         printf("\nSeats available in\n");
        for(int x = 0; x < rows; x++){
            rowFreeCount = 0;
            for(int y = 0; y < cols; y++){
    
                if(theatre[x][y] == 0){
                    rowFreeCount = rowFreeCount + 1;
                }
            }
            printf("Row: %d: %d\n",x,rowFreeCount);
            totalFreeCount = totalFreeCount + rowFreeCount;
            
        }
        printf("\nTotal number of available seats: %d\n", totalFreeCount);
    }
    else{
        printf("\nBooking unsuccessful! No row contains %d consecutive available seats. Seating plan remains unchanged.\n", bookingPeople);
    }

    

}