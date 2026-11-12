#include <stdio.h>
#include <stdlib.h>

void inputData(int rows, int cols,int *grid);
void tempAnalysis(int rows, int cols,int *grid);
void highestAverage(int rows, int cols, int *grid);

int main(){

    int sensors = 0;
    int hours = 0;

    printf("Enter number of sensors: ");
    scanf("%d", &sensors);

    printf("Enter number of hours: ");
    scanf("%d", &hours);

    int *array = (int *)malloc(sensors*hours * sizeof(int));    //Allocates a block of memory for the 2d array
    if(array == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    inputData(sensors,hours,array);
    tempAnalysis(sensors,hours, array);
    highestAverage(sensors, hours, array);

    free(array);

    return 0;

}

void inputData(int rows, int cols, int *grid){

    for(int x = 0; x< rows; x++){
        printf("Sensor %d:\n",x);

        for(int y = 0; y< cols; y++){
            printf("Enter temperature reading for hour %d: ",y);
            scanf("%d", &grid[x * cols + y]);
            printf("\n");
        }
        printf("\n");
    }
}

void tempAnalysis(int rows, int cols, int *grid){

    for(int x = 0; x < rows; x++){
        
        float avgTemp = 0;
        int totalTemp = 0;
        int lowestTemp = 1000;
        int highestTemp = -10;
        int critCount = 0;
        int warnCount = 0;
        int countStreak = 0;
        int streak = 0; 

        for(int y = 0; y < cols; y++){      //Iterates each hour
            totalTemp = totalTemp + grid[x * cols + y];     //Sums up all temps calculated for current sensor

            if(grid[x * cols + y] > highestTemp){       //Highest temp of sensor stored
                highestTemp = grid[x*cols + y];
            }

            if(grid[x * cols + y] < lowestTemp){        //Lowest temp of sensor stored
                lowestTemp = grid[x*cols + y];
            }

            if(grid[x * cols + y] > 40){        //Sums amount of times temps reached 40 or above
                critCount++;
            }
            
            if(grid[x * cols + y] >= 35 && grid[x * cols + y] <= 39){       //Sums amount of times temps sat between 40 and 35(inclusive)
                warnCount++;
            }

            if(grid[x * cols + y] >= 35){       //Counts streak
                streak++;

                if(streak > countStreak){
                    countStreak = streak;
                }
            }
            else{
                streak = 0;
            }
        }

        avgTemp = (float)totalTemp/cols;

        printf("Sensor %d: ",x);
        printf("Total=%d  ", totalTemp);
        printf("Avg=%.2f  ",avgTemp);
        printf("Max=%d  ",highestTemp);
        printf("Min=%d\n",lowestTemp);
        printf("Critical=%d  Warning=%d  Longest hot streak=%d",critCount,warnCount,countStreak);

        printf("\n \n");

}
}

void highestAverage(int rows, int cols, int *grid){
    float highestAverage = -1;
    int highestSensor  = 0;
    float average = 0;
    
    for(int x = 0; x < rows; x++){
        int sum = 0;

        for(int y = 0; y < cols; y++){
           sum = sum + grid[x * cols + y];
        }
        
        float average = (float)sum/cols;
        if(average > highestAverage){
            highestAverage = average;
            highestSensor = x;
        }
    }
    printf("Highest average: Sensor %d (%.2f)",highestSensor,highestAverage);
}