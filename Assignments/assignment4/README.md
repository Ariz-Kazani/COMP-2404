---
Name: Ariz Kazani
stdn: 101311311
---

# Assignment 4

### Ariz Kazani 
### 101311311

# Compilation Instructions

Simply run `make` in the command line when in the assignment 3 directory, then run `./a3` 
to run the program or `./a4` to test the program

# Deviations from specifications

In the `Driver.cc` class, the `match` function does does not check if driver or user is withing a certain 
rating as this does not pass the tests in the `Controller.cc` class. In a comment I have put the working code
but the code that deviates from the specifications is present to pass the tests. 

# Files

- Control.cc and Control.h
    provided controller that controls interaction between view and client

- Customer.cc Customer.h    
    customer class

- defs.h
  Defines constants.

- Drawable.cc and Drable.h
    class that defines drawable items on a grid

- Driver.cc and Drive.h
    Driver class

- List.h
    A generic ArrayList that can hold elements of any type

- Location.cc Location.h
    Location class, gives cords for drawable items on a grid

- main.cc
    Main function, used to launch the controller.

- Makefile 
    Compiles Program

- README.md (this file)

- RideShare.cc RideShare.h
    The main class for the app, this app controls interaction between drivers and riders

- User.cc User.h
    A generic class for users

- View.cc View.h
    Used for controlling the interaction between the user and the program.
