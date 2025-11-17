#include <stdio.h>
#include "include/functions.h"

// Define the Car structure
extern struct Car cars[10];

void userMenu()
{
    int userChoice;
    do
    {
        printf("\n--- User Menu ---\n");
        printf("1. View Available Cars\n");
        printf("2. Rent a Car\n");
        printf("3. Return a Car\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice)
        {
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
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (userChoice != 4);
}
