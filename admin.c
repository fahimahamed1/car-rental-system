#include <stdio.h>
#include "include/functions.h"

#define ADMIN_PASSWORD "fahim"

int isAdminLogin() {
    char password[20];
    int retries = 3;

    while (retries > 0) {
        printf("Enter Admin Password (Attempts remaining: %d): ", retries);
        scanf("%s", password);

        int i = 0;
        while (password[i] != '\0' && ADMIN_PASSWORD[i] != '\0') {
            if (password[i] != ADMIN_PASSWORD[i]) {
                break;
            }
            i++;
        }

        if (password[i] == '\0' && ADMIN_PASSWORD[i] == '\0') {
            return 1;
        } else {
            printf("Incorrect password. Please try again.\n");
            retries--;
        }
    }

    printf("You have entered the incorrect password too many times.\n");
    return 0;
}

void adminMenu() {
    int adminChoice;
    do {
        printf("\n--- Admin Menu ---\n");
        printf("1. Add New Car\n");
        printf("2. Remove Car\n");
        printf("3. View All Cars\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &adminChoice);

        switch (adminChoice) {
            case 1:
                addNewCar();
                break;
            case 2:
                removeCar();
                break;
            case 3:
                viewAllCars();
                break;
            case 4:
                printf("Logging out from Admin Menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (adminChoice != 4);
}
