# Car Rental System  

## Overview  
The **Car Rental System** is a modular, console-based application developed in C. It provides both **Admin** and **User** panels to manage car rentals efficiently. Admins can add, remove cars and view the inventory, while users can browse available cars, rent them, and return them.

## Features  

### **Admin Panel**  
- Add new cars to the system.  
- View the list of available cars.
- Delete cars from the inventory.

### **User Panel**  
- (Future) User signup and authentication.
- Browse available cars for rent.
- Rent a car and (Future) generate a rental receipt.
- Return a rented car.

## Technologies Used  
- **Programming Language**: C  
- **Modular Programming**: Organized into separate modules for maintainability.
- **Data Storage**: Currently uses in-memory arrays; future versions may include file handling or databases.
- 
## How to Use  
1. Clone the repository:  
   ```sh
   git clone https://github.com/fahimahamed1/car-rental-system.git
   cd car-rental-system
   ```
2. Compile the program:  
   ```sh
  gcc -Iinclude *.c -o carRent
   ```
3. Run the program:  
   ```sh
   ./carRent
   ```
4. Choose either **Admin** or **User** mode to perform actions.  

## Future Enhancements  
- Implement a **database** for better data storage.  
- Add a **payment system** for online transactions.  
- Develop a **GUI version** for improved usability.  
- Add features like user accounts, and rental history.

## Author
Fahim Ahamed

## License  
This project is open-source and available under the **MIT License**.