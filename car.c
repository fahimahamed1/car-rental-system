#include <stdio.h>
#include "include/functions.h"

// Define the Car structure
struct Car cars[10] = {
    {1, "Toyota Corrolla", 2024, 1},
    {2, "Tesla Model 3", 2024, 1},
    {3, "BMW 3 Series", 2023, 1},
    {4, "Audi A4", 2023, 1},
    {5, "Mercedes C-Class", 2022, 1}
};

int carCount = 5;
void viewAllCars() {
    printf("\n--- All Cars ---\n");
    if (carCount == 0) {
        printf("No cars available in the system.\n");
        return;
    }
    for (int i = 0; i < carCount; i++) {
        printf("Car ID: %d, Model: %s, Year: %d, Available: %s\n", 
               cars[i].carID, cars[i].model, cars[i].year, 
               cars[i].available ? "Yes" : "No");
    }
}

void addNewCar() {
    if (carCount < 10) {
        struct Car newCar;
        newCar.carID = carCount + 1; // Assign the next car ID
        newCar.available = 1;       // New car is available by default

        printf("Enter Car Model: ");
        scanf("%s", newCar.model);

        printf("Enter Car Year: ");
        scanf("%d", &newCar.year);

        // Add the new car to the array
        cars[carCount] = newCar;
        carCount++; // Increment carCount AFTER adding the car

        printf("New car '%s' added successfully!\n", newCar.model);
    } else {
        printf("Maximum limit of 10 cars reached. Can't add more cars.\n");
    }
}

void removeCar() {
    int carID;
    printf("Enter the Car ID to remove: ");
    scanf("%d", &carID);

    int index = -1;
    for (int i = 0; i < carCount; i++) {
        if (cars[i].carID == carID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Car ID not found.\n");
        return;
    }

    for (int i = index; i < carCount - 1; i++) {
        cars[i] = cars[i + 1];
    }

    carCount--;
    printf("Car ID %d removed successfully.\n", carID);
}

void rentCar()
{
    int carID;
    printf("Enter the Car ID you want to rent: ");
    scanf("%d", &carID);

    if (carID >= 1 && carID <= carCount && cars[carID - 1].available)
    {
        cars[carID - 1].available = 0;
        printf("You have successfully rented '%s'.\n", cars[carID - 1].model);
    }
    else
    {
        printf("Sorry, the car is either not available or the ID is invalid.\n");
    }
}

void returnCar()
{
    int carID;
    printf("Enter the Car ID you want to return: ");
    scanf("%d", &carID);

    if (carID >= 1 && carID <= carCount && !cars[carID - 1].available)
    {
        cars[carID - 1].available = 1;
        printf("You have successfully returned '%s'.\n", cars[carID - 1].model);
    }
    else
    {
        printf("Sorry, either the car ID is invalid or the car was not rented.\n");
    }
}