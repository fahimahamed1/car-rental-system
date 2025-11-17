#include <stdio.h>
#include "include/functions.h"

int main() {
    int choice; //declared veriable
    
    do {
        printf("\n--- Car Rental System ---\n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("3. Exit\n");
        printf("Select your role: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isAdminLogin()) {
                    adminMenu();
                } else {
                    printf("Invalid admin password!\n");
                }
                break;
            case 2:
                userMenu();
                break;
            case 3:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
