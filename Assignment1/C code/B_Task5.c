//Code function: Smart Campus parking and access management system

#include <stdio.h>

int main() {    //Start of main function
    int processed = 0;      //total number of vehicles processed
    int success = 0;        //total number of vehicles  ehich were given parking
    int reject = 0;         //total number of vehicles which were rejected parking
    int standard_vehicle = 0;       //Cars and Bikes
    int large_vehicle = 0;          //Vans

    int zoneA_cap = 20;     //Parking capacity of Zone A
    int zoneB_cap = 40;     //Parking capacity of Zone B
    int zoneC_cap = 15;     //Parking capacity of zone C    

    int total_vehicles;     //Value will be input to tell how many vehicles will enter for parking
    int x;                  

    char vehicle_type;      
    char user_cat;
    char permit;
    char emergency;

    int zoneA_occupancy;    //Actual Occupancy of zones as zones are of different sizes
    int zoneB_occupancy;
    int zoneC_occupancy;

    printf("Enter total vehicles\n");
    scanf("%d", &total_vehicles);   //Input number of vehicles waiting for parking

    for (x = 1; x <= total_vehicles; x++) {         //For loop which will run for the amount of total vehicles
        printf("Enter Vehicle Type: (C)ar, (B)ike, (V)an\n");
        scanf(" %c", &vehicle_type);                //input Vehicle type

        printf("Enter user category: (F)aculty, (S)tudent, (G)uest\n");
        scanf(" %c", &user_cat);                    //Input User Category(Parking zone will be determined using this)

        printf("Valid parking permit?: (Y)es or (N)o\n");
        scanf(" %c", &permit);                      //Valid permit check

        printf("Emergency Vehicle? (Y)es or (N)o\n");
        scanf(" %c", &emergency);

        // Validation of inputs
        while (vehicle_type != 'C' && vehicle_type != 'c' && vehicle_type != 'B' && vehicle_type != 'b' && vehicle_type != 'V' && vehicle_type != 'v') {
            printf("Enter valid vehicle type\n");
            scanf(" %c", &vehicle_type);
        }

        while (user_cat != 'F' && user_cat != 'f' && user_cat != 'S' && user_cat != 's' && user_cat != 'G' && user_cat != 'g') {
            printf("Enter valid user category\n");
            scanf(" %c", &user_cat);
        }

        while (permit != 'Y' && permit != 'y' && permit != 'N' && permit != 'n') {
            printf("Enter valid parking permit status\n");
            scanf(" %c", &permit);
        }

        while (emergency != 'Y' && emergency != 'y' && emergency!= 'N' && emergency != 'n') {
            printf("Enter valid emergency status\n");
            scanf(" %c", &emergency);
        }

        if (permit == 'Y' || permit == 'y' || emergency == 'Y' || emergency == 'y') {       //Runs further if either permit is valid or vehicle is emergency
            if (user_cat == 'F' || user_cat == 'f') { //Zone A
                if (vehicle_type == 'B' || vehicle_type == 'b' || vehicle_type == 'C' || vehicle_type == 'c') {     //Zone A standard vehicles
                    if (zoneA_cap >= 1) {                                       
                        success = success + 1;                                  //Checks whether Zone A has atleast one available free space. If so, it increments value of success
                        zoneA_cap = zoneA_cap - 1;                              //by one to show parking of vehicle was successful and decrements value of ZoneA capacity to update left 
                        printf("Remaining Capacity: %d\n", zoneA_cap);          //amount of space. Outputs to park in zone A and increments processed.Adds 1 to count of total standard vehicles.
                        standard_vehicle = standard_vehicle + 1;                //If no available free space, outputs  message and increments reject
                        printf("Park in Zone A\n");
                        processed = processed + 1;
                    } else {
                        printf("No available space\n");
                        reject = reject + 1;
                        processed = processed + 1;
                    }
                } else { //Zone A Vans                                          //Checks whether Zone A has atleast two available free spaces. If so, it increments value of success
                    if (zoneA_cap >= 2) {                                       //by one to show parking of vehicle was successful and decrements value of ZoneA capacity by 2 to update left 
                        success = success + 1;                                  //amount of space. Outputs to park in zone A and increments processed. If no available free space, outputs
                        zoneA_cap = zoneA_cap - 2;                              //message and increments reject. Adds 1 to count of total large vehicles if accepted.
                        printf("Remaining Capacity: %d\n", zoneA_cap);
                        printf("Park in Zone A\n");
                        large_vehicle = large_vehicle + 1;
                        processed = processed + 1;
                    } else {
                        printf("No available space\n");
                        reject = reject + 1;
                        processed = processed + 1;
                    }
                }
            } else if (user_cat == 'S' || user_cat == 's') {    // Zone B
                if (vehicle_type == 'B' || vehicle_type == 'b' || vehicle_type == 'C' || vehicle_type == 'c') {     //Zone B standard vehicles
                    if (zoneB_cap >= 1) {
                        success = success + 1;
                        zoneB_cap = zoneB_cap - 1;
                        printf("Remaining space: %d\n", zoneB_cap);
                        standard_vehicle = standard_vehicle + 1;                //Works the same as above mentioned 2 comments but for zone B
                        processed = processed + 1;
                        printf("Park in Zone B\n");
                    } else {
                        printf("No available space\n");
                        reject = reject + 1;
                        processed = processed + 1;
                    }
                } else {    //Vans
                    if (zoneB_cap >= 2) {
                        success = success + 1;
                        zoneB_cap = zoneB_cap - 2;
                        printf("Remaining space: %d\n", zoneB_cap);
                        large_vehicle = large_vehicle + 1;
                        processed = processed + 1;
                        printf("Park in Zone B\n");
                    } else {
                        printf("No available space\n");
                        reject = reject + 1;
                        processed = processed + 1;
                    }
                }
            } else if (user_cat == 'G' || user_cat == 'g') { // Zone C
                if (vehicle_type == 'B' || vehicle_type == 'b' || vehicle_type == 'C' || vehicle_type == 'c') {
                    if (zoneC_cap >= 1) {
                        success = success + 1;
                        zoneC_cap = zoneC_cap - 1;
                        printf("Remaining space: %d\n", zoneC_cap);
                        standard_vehicle = standard_vehicle + 1;                //(Check comment above) Works for zone C
                        processed = processed + 1;
                        printf("Park in Zone C\n");                             
                    } else {
                        printf("No available space\n");
                        reject = reject + 1;
                        processed = processed + 1;
                    }
                } else {    //Vans
                    if (zoneC_cap >= 2) {
                        success = success + 1;
                        zoneC_cap = zoneC_cap - 2;
                        printf("Remaining space: %d\n", zoneC_cap);
                        large_vehicle = large_vehicle + 1;
                        processed = processed + 1;
                        printf("Park in Zone C\n");
                    } else {
                        printf("No available space\n");
                        reject = reject + 1;
                        processed = processed + 1;
                    }
                }
            }
        } else {
            printf("No permit\n");
            reject = reject + 1;
            processed = processed + 1;
        }
    }

    // Print Summary
    printf("Summary:\n");
    printf("Total number of vehicles: %d\n", processed);
    printf("Total accepted vehicles: %d\n", success);
    printf("Total rejected vehicles: %d\n", reject);
    printf("Total number of cars and bikes successfully parked: %d\n", standard_vehicle);
    printf("Total number of vans successfully parked: %d\n", large_vehicle);
    printf("Remaining capacity of zone A: %d\n", zoneA_cap);
    printf("Remaining capacity of zone B: %d\n", zoneB_cap);
    printf("Remaining capacity of zone C: %d\n", zoneC_cap);

    zoneA_occupancy = 20 - zoneA_cap;
    zoneB_occupancy = 40 - zoneB_cap;
    zoneC_occupancy = 15 - zoneC_cap;

    if (zoneA_occupancy > zoneB_occupancy && zoneA_occupancy > zoneC_occupancy) {                   
        printf("Zone A had highest occupancy\n");
    } else if (zoneB_occupancy > zoneA_occupancy && zoneB_occupancy > zoneC_occupancy) {
        printf("Zone B had highest occupancy\n");
    } else if (zoneC_occupancy > zoneA_occupancy && zoneC_occupancy > zoneB_occupancy) {
        printf("Zone C had highest occupancy\n");
    } else if (zoneA_cap == 0 && zoneB_cap == 0 && zoneC_cap == 0) {
        printf("Whole parking full\n");
    }

    return 0;
}   //End of main functiom