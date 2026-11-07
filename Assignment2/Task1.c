#include <stdio.h>

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
                  printf("X  ");
            else{
                printf("_  ");
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

    //Group booking
    int bookingPeople = 0;
    printf("\n\nEnter total number of people for group booking: ");
    scanf("%d", &bookingPeople);
}
