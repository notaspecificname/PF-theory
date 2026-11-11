#include <stdio.h>
#include <stdlib.h>

int getValidDays();
float calculateDailySales(int dayNumber); 
int findHighestSalesDay(float *SalesArr, int numberOfDays);
void displayBarChart(float *SalesArr, int numberOfDays);

int main(){
    float totalFestSales = 0;
    int festDays = getValidDays();
    float *dailySales = (float *)malloc(festDays * sizeof(float));
    
    for(int x = 0; x < festDays; x++){
        dailySales[x] = calculateDailySales(x+1);
    }

    for(int x = 0; x < festDays; x++){     
       totalFestSales = dailySales[x] + totalFestSales;
       }

    printf("==== FESTIVAL SUMMARY ====\n");

    printf("Total festival Sales: Rs. %.2f\n", totalFestSales);
    printf("Highest daily sales: Rs ");
    int largestDay = findHighestSalesDay(dailySales,festDays);
    printf("\nDay with highest sales: Day %d\n\n",largestDay);

    printf("==== DAILY SALES BAR CHART ====\n");
    displayBarChart(dailySales,festDays);

    free(dailySales);
}


int getValidDays(){     //Inputs and validates the number of festival days entered(must be between 1 and 7) and returns it

    int festDur = 0;

    printf("Enter Festival duration: ");
    scanf("%d", &festDur);
    while(festDur < 1 || festDur > 7){
        printf("Enter a value between 1 and 7!: ");
        scanf("%d", &festDur);      
    }

    return festDur;
}

float calculateDailySales(int dayNumber){

    int numOfOrders = 0;
    float value = 0;
    float avgOrderVal = 0;
    float maxOrderVal = 0;
    float sum = 0;
    
        printf("Day %d\n",dayNumber);
        printf("Enter number of orders: ");
        scanf("%d",&numOfOrders);

        while(numOfOrders < 1){
            printf("Enter a value greater than 0: ");
            scanf("%d",&numOfOrders);
        }

        for(int y = 0; y < numOfOrders; y++){
            printf("Enter value of order number %d: ", y+1);
            scanf("%f",&value);

            while(value < 1){
            printf("Enter a value greater than 0: ");
            scanf("%f",&value);
        }

            sum = sum + value;
            if(value > maxOrderVal){
                maxOrderVal = value;
            }
        }

        avgOrderVal = sum / numOfOrders;
        printf("**** Day %d ****\n",dayNumber);
        printf("Total Sales: %.2f\n",sum);
        printf("Average Order: %.2f\n", avgOrderVal);
        printf("Highest Order: %.2f\n\n",maxOrderVal);

        return sum;
    }

int findHighestSalesDay(float *SalesArr, int numberOfDays){

    float largest = SalesArr[0];
    int largestDay = 1;     //Will store the day with the most sales

    for(int x = 0; x< numberOfDays; x++){

        if(SalesArr[x] > largest){
            largest = SalesArr[x];
            largestDay = x+1;
        }
    }
    printf("%.2f",largest);
    return largestDay;
}

void displayBarChart(float *SalesArr, int numberOfDays){

    for(int x = 0; x < numberOfDays; x++){
        float daySales = SalesArr[x];

        printf("Day %d: ",x+1);
        while(daySales >= 100){
            printf("*");
            daySales = daySales - 100;
        }
        printf(" (Rs. %.2f)",SalesArr[x]);
        printf("\n");
    }
}