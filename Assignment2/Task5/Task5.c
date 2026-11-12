#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registerMember(char name[], int *studentID, int *memberType);
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[],int totalBooks);
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType);

int main(){


}

void registerMember(char name[], int *studentID, int *memberType){

    printf("Enter full name: ");
    fgets(name,100,stdin);

    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    printf("Enter Student ID: ");
    scanf("%d",studentID);

    printf("Enter Member type : ");
    printf("Enter 1 for student \n");
    printf("Enter 2 for Faculty");
    scanf("%d", memberType);

    while(*memberType != 1 && *memberType != 2){
        printf("Enter a valid number! ");
        scanf("%d", memberType);
    }

}

void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[],int totalBooks){

    for(int x = 0; x < totalBooks; x++){
        printf("%d | %c | %d", bookIDs[x], bookTitles[x], availableCopies[x]);
    }
}

void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType){

    
}