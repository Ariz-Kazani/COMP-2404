---
STUDENT: Ariz Kazani
CODE: COMP 2404
NAME: Introduction to Software Engineering
LANGUAGES: C++
Semester: Fall 2024
Instructor: Darryl Hill
---

# COMP 2404 FALL 2024 Course Notes

## Background

This is all of my course work completed in the fall of 2024 with Prof. Darryl Hill. 
This repository has been made public with the permission of prof Prof. Darryl. All code 
was written in an linux vm by me and *should* be compatible with most unix based 
systems. All data is in the main branch, if you notice any other branches, they were
purely used for submission purposes. There are two folders, Tutorials and Assignments
Tutorials were small exercises that would prepare us for the assignments. Assignments 
were larger projects.

## Tutorials

### Tutorial 1
#### Introduction to basic concepts, such as variables, input and output and output parameters.

### Tutorial 2
#### Introduction to classes and namespaces

"In this tutorial you will simulate a battle between two Characters, an orc from Mordor and a fighter from Gondor. If they fight in Gondor, the fighter will have the advantage, and if they fight in Mordor, the orc will have the advantage. These two places will be defined by their namespaces.

You will make a class Character to represent the orc and the fighter. This will include both Character.h and Character.cc files. In addition you will have files battle.h and battle.cc. These two files should define two global fight functions in different namespaces. Note: battle is not a class. The battle.h file contains the function prototypes and the battle.cc contains the function implementations. Finally you will have a main.cc file with a main function to run the battle."


### Tutorial 3
#### Learn to use GIT, submit a file to gradescope using git

### Tutorial 4
#### Memory management 

"In this tutorial you will complete two more classes from Assignment 2: the FileList class (Section 5.4.1) and the Repo class (Section 5.5). In addition, if you have not yet completed it, you will also complete the Date and File classes from Section 5.2 and 5.3. There is a test file provided, test.cc, that calls on TestControl and Tester to test the functions that you provide from those classes. You are provided with a Makefile - make any changes you see fit (and remember that Linux is case sensitive!). As usual the test script, t4test.py is provided. This script is run with valgrind, so it will check the valgrind output to see if there are memory leaks or invalid reads or invalid frees."

### Tutorial 5
#### Memory management with data structures 

"In this tutorial you will provided the modified versions of the Date and File (Section 6.2) classes. These are classes originally from Assignment 2 Sections 5.1 and 5.2, but you will modify them for Assignment 3 according to the instructions in Section 6.1 and 6.2. 
    
You will also write two other classes, HeapArrays and StackArrays. There is a test file provided, test.cc that will test the functions that you provide from those classes. There is a second test file, test2.cc, that will test whether you properly const’d your classes. A Makefile that compiles all classes into object files and compiles test.cc and test2.cc into executables is provided. As usual the test script, t5test.py is provided. This time the script is run with valgrind, so it will check the valgrind output to see if there are memory leaks."

### Tutorial 6
#### Memory management with objects (destructors and deep-copy's)

"In this tutorial you will complete two more classes from Assignment 3: the FileList class (Section 6.4) and the Repo class (Section 6.3). In addition, if you have not yet completed it, you will also complete the Date and File classes from Section 6.2. There is a test file provided, test.cc, that calls on TestControl and Tester to test the functions that you provide from those classes. You are provided with a Makefile - make any changes you see fit (and remember that Linux is case sensitive!). As usual the test script, t6test.py is provided. This script is run with valgrind, so it will check the valgrind output to see if there are memory leaks or invalid reads or invalid frees."

### Tutorial 7
#### Inheritance, templates, and function pointers

"Write the Drawable, User, Driver and Customer classes from Assignment 3, Sections 6.2 - 6.7. This tutorial tests that you have constructed the id correctly, and tests the List class to ensure your compare function is working correctly. This does NOT test the Drawable or View classes, but since Customer and Driver inherit from Drawable, and Drawable uses a View, they should be included."

### Tutorial 8
#### Multiple inheritance and polymorphism

"Write the Episode and all of the Search classes from Assignment 4, Sections 5.1 and 5.4. This tutorial tests the matches functions from your Search classes, as well as checks that you have overloaded the stream insertion operator (<<) correctly (using polymorphism)."

### Tutorial 9
#### "Template" a class implement operator overloading

"If you have not already, write the Episode class from Assignment 5, Section 5.4. In particular, ensure that you have implemented the Episode::operator<<. Then complete the Array class from Section 5.2."

### Tutorial 10
#### Learn to use the STL library

"In this tutorial you are to implement an Algorithms class. This class will read in a collection Student objects and perform different operations on them such as sorting."

## Assignments

### Assignment 1
#### Implement simple C++ features and learn to make a makefile

"You will make an app that manages reservations for a Campground. A Campground consists of Campsites. Each Campsite has a Category, which is an enum consisting of entries such as tent or cabin, and Campsites can be reserved by Campers. To manage the reservations, and ensure that we do not have Campsites reserved to more than one group on a given day, you will modify the Date class that we saw in class. 

We will be implementing a basic back-end of the application, but not a user-facing interface. Instead of a user-facing interface you will be supplied with a test suite for your application."

### Assignment 2
#### Use MVC principals, collection classes, intro to memory management

"You will be writing C++ code that mimics version tracking system (like Git and Github). GetHub stores Repos, and these Repos contain Files that are being tracked. GetHub will have functions to add, view, and remove Repos and Files. We will limit ourselves to this functionality in this assignment. In the next assignment we may extend this functionality to be more of a version management system."

### Assignment 3
#### Update code bases, change implementations while keeping same interface, making UML diagrams, constructors, encapsulation

"This is a continuation of the GetHub project from assignment 2. As a starting point, you may use your own assignment, or use the code provided. In addition to changing existing classes, you will implement a Client class that can “download” (i.e., make a deep copy of) a Repo, and then print the Files it contains. As before there is a Control class that connects and coordinates the functionality of your classes with a View class. In addition there is a separate TestControl class that allows you to run tests. You will be required to make a UML diagram of the completed project."

### Assignment 4
#### Use  class hierarchies, multiple inheritance, and polymorphism, implement static members, function pointers, templates, use a visitor design pattern

"In this assignment you will implement an Uber-like application called RideShare. RideShare maintains two lists of Users, broken down into Customers and Drivers, each with a current location in the city. These Customers and Drivers will be Drawable objects, and they will be able to draw themselves on a View. The actual drawing code for this particular View is done for you (the graphics will blow you away). In the draw function you simply make the correct function calls on the View. 

A Customer can request a ride from our app. When a ride is requested, the closest Driver that has the proper criteria is selected (big enough and good enough rating). The Customer is notified and transported to their new location. 

The application gives the option of displaying the map, which displays the location of all Customers and Drivers in the city (Customers are shown in buildings while Drivers are shown on the road). Since these things are drawn (slightly) differently (and at some point we may want to make a better View), we will use multiple dispatch to draw these elements to the map, implemented here using a Visitor pattern (which is a common approach to multiple dispatch in C++)."

### Assignment 5
#### Operator overloading, templates, multiple inheritance in a diamond hierarchy, Factories

"In this assignment we will implement a podcast network called Podify. The Podify network holds Podcasts which have Episodes. You will implement a Search object which will match Episodes that meet certain criteria and put them in a playlist. You can then list all Episodes in the playlist, or play all Episodes in the playlist. When you play Episodes, you have the option of playing with or without a video element (which is some random ASCII art). Podcasts, Episodes, and Search objects will be made using a PodcastFactory. Though the PodcastFactory will create these objects, you must delete them when you are finished with them."


## Credits

All code was written by Prof. Daryl Hill from Carleton University, whom designed 
the tutorials and assignments. The assignments and tutorials were complete by Ariz 
Kazani :). 
