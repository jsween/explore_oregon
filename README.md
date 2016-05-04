# explore_oregon

## By Jonathan Sweeney

# Description

Algorithm:

1.	Welcome the user to the program.
1.1	Display the purpose of the program to the user. 
1.2	In the welcoming message, the menu options for the user are going to be displayed.  For example, the message will inform the user that they will be adding an activity, searching for activities within a set number of miles, display all of the activities and the last option is to quit.
2.	 Get the number of events.
2.1 This step will set the maximum number of activities that the user can add into the program.
3.	In order to allow the user to quickly add an activity, search for activities within a defined number of miles, display all activities, or quit the program, there will be a switch statement.  Each option will have their own unique code to select them.  The menu options for the user are as follows:
3.1	Add an Activity.  This will be where a user adds an activity.  The function will also call another function to get the activity’s:
1. Name (e.g., Wind Surfing) 
2. Description 
3. Location (e.g., Columbia Gorge) 
4. Distance from Portland (in miles) 
5. Notes and Suggestions
3.2	Display Area.  This allows the user the ability to search for activities within a number of miles.
3.3	Display All.  This option allows the user to see all of the activities that have been added by the user.  
3.4	Quit the Program.  This option allows the user to exit the program.  The do-while loop will continue until the user enters the correct number to exit the program.
3.5	If anything number other than quit (99) is entered, the program will loop back to the beginning of step 2. 

Design Considerations:
1.	 There will be an activity.h, main.cpp, and activity.cpp file.  The header file will contain the prototypes, constants and the activity and event class.  The main.cpp file will have the main function and only contain the welcome message, constructors and switch function.  The activity.cpp will have the bulk of the work, including the build function for the linear linked list. 
2.	Activity Class – This will be the manager class that will be managing the data.  The integer size will determine the maximum number of activities that can be entered.  The class will also have the 3 main functions where the user adds an activity, searches within a number of miles and display all of the activities.  
3.	Event Class – This class will be storing all of the information of an activity.  The same supporting functions will be stored too.  
4.	Linear Linked List – This list will contain all of the objects stored in the activity array.


Functions:
1.	Functions that I will be using.
1.1	Welcome function.  This will be the first function in the main function.  This will just simply welcome the user and give brief statements over what the program does for the user.
1.2	Get the number of activities.  This function will determine how many activities can be stored.  
1.3	Switch option function.  This function has a switch statement that is the most critical piece of the whole program.  The user inputs the number corresponding with the option.  It will be a loop until the user enterers 99.
1.4	Add an activity.  This function will store the activity object’s information.  This will be a name, description, location, distance from Portland and any additional notes.  This will be stored in an array.
1.5	Get the number of miles.  This will be a simple function that find the number of miles the user wants to search from Portland.  It will either store the information into a variable or return the amount.
1.6	Display Area.  This function will pass in the number of miles from Portland variable.  It will search the event class and compare the number of miles from Portland variable to the value of miles from Portland variable stored in the object.  
1.7	Display All.  This function will contain the build function for the linear linked list.  The build function will pass in the objects stored in the array.
1.8	Their will be an activities constructor and destructor.  These will allocate and deallocate the memory, respectively.
1.9	Compare activity name function.  This function will compare the activity names and insert the activities along the linear linked list in alphabetical order.

