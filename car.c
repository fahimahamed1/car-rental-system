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
        newCar.carID = carCount + 1; 
        newCar.available = 1;

        printf("Enter Car Model: ");
        scanf("%s", newCar.model);

        printf("Enter Car Year: ");
        scanf("%d", &newCar.year);

        cars[carCount] = newCar;
        carCount++;

        printf("New car '%s' added successfully!\n", newCar.model);
    } else {
        printf("Maximum limit of 10 cars reached. Can't add more cars.\n");
    }
}

void removeCar() {
    int carID;
    printf("Enter the Car ID to remove (or 0 to go back): ");
    scanf("%d", &carID);

    if (carID == 0) return; // Back option

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

void rentCar() {
    printf("\n--- Available Cars ---\n");
    int availableCount = 0;
    for (int i = 0; i < carCount; i++) {
        if (cars[i].available) {
            printf("Car ID: %d, Model: %s, Year: %d\n", cars[i].carID, cars[i].model, cars[i].year);
            availableCount++;
        }
    }
    if (availableCount == 0) {
        printf("No cars available for rent.\n");
        return;
    }

    int carID;
    printf("Enter the Car ID you want to rent (or 0 to go back): ");
    scanf("%d", &carID);

    if (carID == 0) return;

    if (carID >= 1 && carID <= carCount && cars[carID - 1].available) {
        cars[carID - 1].available = 0;
        printf("You have successfully rented '%s'.\n", cars[carID - 1].model);
    } else {
        printf("Sorry, the car is either not available or the ID is invalid.\n");
    }
}

void returnCar() {
    printf("\n--- Rented Cars ---\n");
    int rentedCount = 0;
    for (int i = 0; i < carCount; i++) {
        if (!cars[i].available) {
            printf("Car ID: %d, Model: %s, Year: %d\n", cars[i].carID, cars[i].model, cars[i].year);
            rentedCount++;
        }
    }
    if (rentedCount == 0) {
        printf("No cars are currently rented.\n");
        return;
    }

    int carID;
    printf("Enter the Car ID you want to return (or 0 to go back): ");
    scanf("%d", &carID);

    if (carID == 0) return;

    if (carID >= 1 && carID <= carCount && !cars[carID - 1].available) {
        cars[carID - 1].available = 1;
        printf("You have successfully returned '%s'.\n", cars[carID - 1].model);
    } else {
        printf("Sorry, either the car ID is invalid or the car was not rented.\n");
    }
}
