//Code purpose: Class result processing

#include <stdio.h>
int main(){     //Main function start

    int sub1;   //All variables starting with sub will store the corresponding subject marks
    int sub2;
    int sub3;
    int sub4;
    int sub5;
    int sum;    //Stores the sum of all sub values
    float avg;  //Stores the calculated average of sub

    printf("Enter Subject 1 marks: ");      //Blcok of code inputs sub values and stores it in correspodon sub ariables
    scanf("%d",&sub1);
    printf("Enter Subject 2 marks: ");
    scanf("%d",&sub2);
    printf("Enter Subject 3 marks: ");
    scanf("%d",&sub3);
    printf("Enter Subject 4 marks: ");
    scanf("%d",&sub4);
    printf("Enter Subject 5 marks: ");
    scanf("%d",&sub5);

    sum = sub1 + sub2 + sub3 + sub4 + sub5;     //Calculates sum  of values
    avg = sum/5;        //Calculates average by divoding sum by 5

    if(sub1>32 && sub2>32 && sub3>32 && sub4>32 && sub5>32){        //Checks if all values are greater than 32, if true then inner if loop else exits after printing fail -- subject defiecincy
        if(avg >= 80)       //Checks if average is greater than or equal to 80, if so prints "Distinction"
            printf("Distinction");
        else if(avg >= 60)      //Checks if average is greater than or equal to 60, if so prints "pass"
            printf("Pass");
        else                    //Prints "Pass" if not fulfilling above conditions
            printf("Fail");
             
        }
    else
        printf("Fail -- Subject Deficiency");
    
    return 0;
}   //Main function end