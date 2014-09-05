List of Files 
The project consists of 2 source code files:

•	Vend.h: Vending Machine Class Definition and Accessors
o	The class definitions along with private and public variables are initialised here. This header file contains the validation methods for checking the stock, calculating change, and confirming payment. Manipulation by the end user, console I/O and variable modification is managed in main.cpp.

•	Main.cpp Vending Machine Main Program
o	Performs the main program operation, presents the menus, and the user prompts, and provides end-user feedback. Objects of the class instantiated are used here. The project, when compiled, is run from this file. All validation is passed to the Vend.h file

Usage
Usage is convenient, but outcomes vary per software package.
1.	IMPORTANT: Please ensure that Vend.h and Main.cpp reside in the same program directory, otherwise the application will not compile.
2.	The app was developed in Dev C++ 5.5.1 thus compiling it and running it through the console is advised. Simply open Main.cpp and press the F11 button, execution will begin.
3.	Follow on-screen prompts during execution.

Implementation
Implementation methods are discussed above and may be evaluated within the source code. Essentially, the code offers a menu for the user to view total purchased cents, view the inventory of items and check stock, or purchase an item. If an item is to be purchased, the user must enter a valid number (error checking is performed) and then deposit money. An error is displayed to the user if they deposit too little, whilst change is returned if they deposit too much.

Bugs
Code throws operator overload errors in Visual Studio 2013 only. NO BUGS in Dev C++.
