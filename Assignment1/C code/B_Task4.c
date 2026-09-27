//Code purpose: Online Shipping Bill Calculator

#include <stdio.h>
#include <stdbool.h>
int main(){

    int q;      //Quantity purchased
    float p;    //Price per item
    float d;    //Discount percentage
    float t;    //Tax percentage
    bool valid1 = true;    //Fisrt valid check, initialized by true
    bool valid2 = true;    //Second valid check, initialized by true
    float s;    //Bill subtotal
    float a;    //Discounted amount
    float final_bill;       //Final calculated bill

    printf("Enter quantity of products: ");
    scanf("%d",&q);
    printf("Enter price per item: ");
    scanf("%f",&p);
    printf("Enter discounted percentage: ");
    scanf("%f", &d);
    printf("Enter tax percentage: ");
    scanf("%f",&t);

    if(q < 0 || p < 0)
    {
        printf("Enter positive values \n");
        valid1 = false;
    }

    if(d >= 100 || t >= 100)
    {
        printf("Percentage should be less than 100");
        valid2 = false;
    }

    if (valid1 == true && valid2 == true)
    {
        s = q*p;        //Calculating subtotal bill by only multiplying amouunt of items purchased with their price
        a = s - (s*d)/100;      //Calculating discounted bill by subtracting the subtotal value with the discount percentage (if d=0 discounted amount eould be equal to subtotal bil)
        final_bill = a + (a * t)/100;   //Calculates final bill by applying tax percentage on discounted bill

        printf("\n \nSubtotal: \t %.2f \n",s);
        printf("Discounted amount: \t %.2f \n",a);
        printf("Final bill: \t %.2f",final_bill);
    }

    return 0;

    
} //End of main function












