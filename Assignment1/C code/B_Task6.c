//Code function: Smart EV Charging and Parking Management System
#include <stdio.h>

int main() {    //Start of main function
    //Initializations
    float discount1 = 0;
    float discount2 = 0;
    float park_charge = 0;
    float price = 0;    //price of charging
    int charging = 0;   //FALSE = 0, TRUE = 1

    char vtype;
    float cur_battery;
    float req_battery;
    float park_duration;
    float current_time;
    char membership;
    char disabled_status;
    char station_available;
    
    float req_charging;
    char *priority = "Normal Charging";
    float total_cost;

    printf("Enter Vehicle type-(E)lectric or (H)ybrid: ");
    scanf(" %c", &vtype);

    printf("Current battery percentage: ");
    scanf("%f", &cur_battery);

    printf("Required charging level: ");
    scanf("%f", &req_battery);

    printf("Enter expected parking duration: ");
    scanf("%f", &park_duration);

    printf("Enter current time in 24-hour format: ");
    scanf("%f", &current_time);

    printf("Have parking membership? (Y or N): ");
    scanf(" %c", &membership);

    printf("Do you have disabled-person priority status?: ");
    scanf(" %c", &disabled_status);

    printf("Is charging station available?: ");
    scanf(" %c", &station_available);

    //Assignmne tof charging prioties and whether to reject charging
    if (station_available == 'Y' || station_available == 'y') {
        if ((vtype == 'H' || vtype == 'h') && cur_battery >= 40) {
            printf("Vehicle doesnot qualify for EV charging\n");
        } else {
            req_charging = req_battery - cur_battery;
            if (req_charging <= 0) {
                printf("No charging required\n");
            } else {
                charging = 1;
                if (cur_battery <= 15 && req_battery >= 80) {
                    priority = "Emergency Charging priority";
                } else if (cur_battery <= 30 && (disabled_status == 'Y' || disabled_status == 'y' || membership == 'Y' || membership == 'y')) {
                    priority = "Priority charging";
                } else {
                    priority = "Normal Charging";
                }
            }
        }
    } else {
        if (vtype == 'H' || vtype == 'h') {
            printf("Charging unavailable - Parking only\n");
        } else {
            printf("No charging slot available\n");
        }
    }

    //Charging price and discount 1 based on membership status
    if (charging == 1) {
        if (current_time < 17.0 || current_time >= 22.0) {
            price = 35;
            if (membership == 'Y' || membership == 'y') {
                discount1 = 20;
            }
        } else if (current_time >= 17.0 && current_time < 22.0) {
            price = 50;
            if (membership == 'Y' || membership == 'y') {
                discount1 = 10;
            }
        }

        if (cur_battery <= 15 && req_battery >= 80) {
            discount1 = 0;
        }
    }

    //Parking charge calculation
    if (park_duration <= 2) {
        park_charge = 200;
    } else if (park_duration <= 5) {
        park_charge = 400;
    } else {
        park_charge = 700;
    }

    //Parking discount 2 based on disabled status
    if (membership == 'Y' || membership == 'y') {
        discount2 = 20;
    } else if (disabled_status == 'Y' || disabled_status == 'y') {
        discount2 = 100;
    }

    //Duration warning
    if (park_duration > 5) {
        printf("Long-stay warning. Please relocate your vehicle after charging\n");
    } else {
        printf("Standard parking duration\n");
    }

    //Output results
    printf("Vehicle type: %c\n", vtype);
    printf("Current battery percentage: %.2f\n", cur_battery);
    printf("Required battery percentage: %.2f\n", req_battery);

    if (charging == 1) {
        printf("Charging priority: %s\n", priority);
        printf("Charging cost: %.2f\n", price);
        printf("Charging discount: %.2f\n", discount1);
    }

    printf("Parking cost: %.2f\n", park_charge);
    printf("Parking discount: %.2f\n", discount2 + discount1);

    total_cost = (price - (price * (discount1 / 100.0))) + (park_charge - (park_charge * (discount2 / 100.0)));   //Calculation of total cost
    printf("Total cost: %.2f\n", total_cost);

    return 0;   //End of main function
}