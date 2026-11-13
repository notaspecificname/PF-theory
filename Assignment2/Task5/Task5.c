#include <stdio.h>

void displayMenu() {
    printf("\n===== UNIVERSITY LIBRARY MENU =====\n");
    printf("1. Register Member\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void registerMember(char name[], int *studentID, int *memberType) {
    printf("Enter name: "); scanf(" %49[^\n]", name);

    printf("Enter student ID: "); scanf("%d", studentID);

    printf("Enter membership type (1 = Student, 2 = Faculty): "); scanf("%d", memberType);

    while (*memberType != 1 && *memberType != 2) {
        printf("Invalid membership type! Enter 1 for Student or 2 for Faculty: ");
        scanf("%d", memberType);
    }

    printf("Member registered successfully.\n");
}

void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks) {
    int index;
    printf("\n%-6s %-25s %s\n", "ID", "Title", "Copies");
    printf("------------------------------------------\n");

    for (index = 0; index < totalBooks; index++)
        printf("%-6d %-25s %d\n", bookIDs[index], bookTitles[index], availableCopies[index]);
}

void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks,
    int borrowedBookIDs[], int *borrowedCount, int memberType) {
    int targetBookID, loanDays, loopIndex, foundIndex = -1;
    int maxAllowedDays = (memberType == 1) ? 14 : 30;

    if (*borrowedCount >= 3) {
        printf("Borrowing limit reached! You can borrow a maximum of 3 books at a time.\n");
        return;
    }

    printf("Enter book ID: "); scanf("%d", &targetBookID);

    for (loopIndex = 0; loopIndex < totalBooks; loopIndex++)
         if (bookIDs[loopIndex] == targetBookID) foundIndex = loopIndex;

    if (foundIndex == -1) {
        printf("Invalid book ID!\n");
        return;
    }

    if (availableCopies[foundIndex] == 0) {
        printf("Sorry no copies of \"%s\" are available.\n", bookTitles[foundIndex]);
        return;
    }

    printf("Enter number of days: "); scanf("%d", &loanDays);

    while (loanDays <= 0) {
        printf("Invalid Days! Enter again: ");
        scanf("%d", &loanDays);
    }

    borrowedBookIDs[(*borrowedCount)++] = targetBookID;
    availableCopies[foundIndex]--;
    printf("You have borrowed \"%s\". Permitted period: %d days.\n", bookTitles[foundIndex], maxAllowedDays);

    if (loanDays > maxAllowedDays)
        printf("Note: the intended period exceeds the permitted %d days; fines apply after %d days.\n", 
            maxAllowedDays, maxAllowedDays);
}

float returnBook(int bookIDs[], int availableCopies[], int totalBooks, int borrowedBookIDs[],
    int *borrowedCount, int memberType, float *totalFine) {
    int targetBookID, actualLoanDays, loopIndex, borrowedIndex = -1, foundIndex = -1;
    int lateDays, maxAllowedDays, fineRatePerDay;
    char inputPromoCode[20], secretPromoCode[] = "LIB2026";
    float computedFine = 0;

    printf("Enter book ID to return: "); scanf("%d", &targetBookID);

    for (loopIndex = 0; loopIndex < *borrowedCount; loopIndex++)
        if (borrowedBookIDs[loopIndex] == targetBookID) borrowedIndex = loopIndex;

    if (borrowedIndex == -1) {
        printf("You have not borrowed this book!\n");
        return 0;
    }

    printf("Enter actual number of days the book was kept: "); scanf("%d", &actualLoanDays);

    while (actualLoanDays <= 0) {
        printf("Invalid Days! Enter again: ");
        scanf("%d", &actualLoanDays);
    }

    for (loopIndex = 0; loopIndex < totalBooks; loopIndex++)
        if (bookIDs[loopIndex] == targetBookID) foundIndex = loopIndex;

    availableCopies[foundIndex]++;

    maxAllowedDays = (memberType == 1) ? 14 : 30;
    fineRatePerDay = (memberType == 1) ? 20 : 10;

    if (actualLoanDays > maxAllowedDays) {
        lateDays = actualLoanDays - maxAllowedDays;
        computedFine = (float)lateDays * fineRatePerDay;

        printf("Book returned late by %d day(s). Late fine: Rs. %.2f\n", lateDays, computedFine);
        *totalFine += computedFine;

        printf("Enter membership code: "); scanf("%19s", inputPromoCode);

        for (loopIndex = 0; secretPromoCode[loopIndex] != '\0' && inputPromoCode[loopIndex] == secretPromoCode[loopIndex]; loopIndex++);
        
        if (secretPromoCode[loopIndex] == '\0' && inputPromoCode[loopIndex] == '\0') {
            computedFine /= 2;
            printf("Correct code! 50%% waiver applied.\n");
        } 
        else {
            printf("Incorrect code. No waiver applied.\n");
        }
        
        printf("Fine payable for this return: Rs. %.2f\n", computedFine);
    } 
    else {
        printf("Book returned on time. No fine.\n");
    }

    for (loopIndex = borrowedIndex; loopIndex < *borrowedCount - 1; loopIndex++)
        borrowedBookIDs[loopIndex] = borrowedBookIDs[loopIndex + 1];

    (*borrowedCount)--;

    return computedFine;
}

void displayMemberRecord(char name[], int studentID, int memberType, int borrowedBookIDs[],
    int borrowedCount, float totalFine, float fineAfterWaiver) {
    int loopIndex;
    printf("\n===== MEMBER RECORD =====\n");
    printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);
    printf("Membership Type: %s\n", (memberType == 1) ? "Student" : "Faculty");
    printf("Currently borrowed books:");

    if (borrowedCount == 0) printf(" None");

    for (loopIndex = 0; loopIndex < borrowedCount; loopIndex++) printf(" %d", borrowedBookIDs[loopIndex]);

    printf("\nTotal fine before waiver: Rs. %.2f\n", totalFine);
    printf("Final fine payable: Rs. %.2f\n", fineAfterWaiver);
}

int main() {
    int catalogBookIDs[4] = {101, 102, 103, 104};
    char catalogBookTitles[4][50] = {"Programming in C", "Data Structures", "Database Systems", "Computer Networks"};
    int catalogCopies[4] = {5, 3, 0, 4};
    int catalogTotalBooks = 4;

    char memberName[50] = "";
    int memberStudentID = 0, membershipCategory = 0, isMemberRegistered = 0;
    int activeBorrowedIDs[3], activeBorrowedCount = 0;
    float totalAccumulatedFine = 0, finalPayableFine = 0;
    int menuChoice;

    do {
        displayMenu();
        scanf("%d", &menuChoice);
        switch (menuChoice) {
            case 1:
                if (isMemberRegistered)
                    printf("A member is already registered.\n");
                else {
                    registerMember(memberName, &memberStudentID, &membershipCategory);
                    isMemberRegistered = 1;
                }
                break;

            case 2:
                displayBooks(catalogBookIDs, catalogBookTitles, catalogCopies, catalogTotalBooks);
                break;

            case 3:
                if (!isMemberRegistered) printf("Please register a member first.\n");
                else borrowBook(catalogBookIDs, catalogBookTitles, catalogCopies, catalogTotalBooks,
                                activeBorrowedIDs, &activeBorrowedCount, membershipCategory);
                break;

            case 4:
                if (!isMemberRegistered) printf("Please register a member first.\n");
                else finalPayableFine += returnBook(catalogBookIDs, catalogCopies, catalogTotalBooks,
                                                   activeBorrowedIDs, &activeBorrowedCount, membershipCategory, &totalAccumulatedFine);
                break;

            case 5:
                if (!isMemberRegistered) printf("Please register a member first.\n");
                else displayMemberRecord(memberName, memberStudentID, membershipCategory, activeBorrowedIDs,
                                         activeBorrowedCount, totalAccumulatedFine, finalPayableFine);
                break;

            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice! Please select 1-6.\n");
        }
    } while (menuChoice != 6);
    return 0;
}