#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Define the Car structure
struct Car
{
    int carID;
    char model[20];
    int year;
    int available;
};

// Declare the external array of cars
extern struct Car cars[10];
extern int carCount;

// Admin functions
int isAdminLogin();
void adminMenu();

// User functions
void userMenu();

// Car management functions
void viewAllCars();
void addNewCar();
void removeCar();
void rentCar();
void returnCar();

#endif
