---
COMP 2404 Assignment 1
Ariz Kazani (101311311)
---

# Assignment 1

### COMP 2404

### Ariz Kazani

### 101311311

# Getting started

Enter the directory of the project using the terminal and enter the command `make`. This will compile and link all of the files. After that is complete, run `./a1` to run the program.

# Files

There are no files that deviate from the specifications, so I wont be explaining them.

- Camper.cc
- Camper.h
- Campground.cc
- Campground.h
- Campsite.cc
- Campsite.h
- Category.cc
- Category.h
- Date.cc
- Date.h
- defs.h
- main.cc
- Makefile
- README.md (this file)
- Tester.cc
- Tester.h

# New Functions

These are the helper functions I wrote, that are not apart of the specifications but make the code more clean and efficient.

### Camper Class

The following are simple getters that are used by other classes.

- Date getStartDate(); 
- Date getEndDate();
- string getName();

### Campground Class

The following are helper functions

- bool campsiteExists(int &position, int site_number);
    
    Checks if the campsite exists in the array of campsites. Updates
    the position if it exits. Returns true if it does.

- void removeSpace(int position);

    Removes the campsite at an index and fills in the space.

###  Campsite Class

The following are simple getters that are used by other classes.

- int getSiteNum();
- Category getCategory();

The following are helper functions.

- bool getVacancy(int &position, Date check_in, Date check_out);

    Checks if a camper can be inserted into the campsite between certain dates. If it can it updates position and returns true. Otherwise it returns false.

- bool bookingsNotClash(Date &endDate, Date &startDate);

    returns whether or not the endDate is before or equal to the startDate.

- void makeSpace(int position);

    Shifts all of the elements from the position to the right by one, making room for a new element

- bool camperExists(int &position, const string &name);

    Returns weather or not a camper exits in the array. The position is updated accordingly 

- void removeSpace(int position);

    Removes the campground at an index and fills in the space.