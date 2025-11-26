#include <stdio.h>
#include <stdlib.h>
#include "include/functions.h"

extern struct Car cars[10];
extern int carCount;

void userMenu() {
    int userChoice;
    do {
        printf("\n--- User Menu ---\n");
        printf("1. View All Cars\n");
        printf("2. Rent a Car\n");
        printf("3. Return a Car\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                viewAllCars();
                break;
            case 2:
                rentCar();
                break;
            case 3:
                returnCar();
                break;
            case 4:
                printf("Logging out from User Menu.\n");
                system(CLEAR);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (userChoice != 4);
}
