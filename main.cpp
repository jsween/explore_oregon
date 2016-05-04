/*
Jonathan Sweeney, CS162, Prog 5, 12/6/15
The purpose of the program is to allow the user to add activities near Portland 
and search for them.
*/

#include "activity.h"

//prototypes
void welcome();
int get_size();
int display_options();
void switch_option(Manager & a_list);

//main
int main()
{

	welcome();					//welcomes user
	int size = get_size();		//gets the num of activities to add
	Manager a_list(size);		//creates an array of structs with 'size' indexes
	switch_option(a_list);		//menu for user to choose the options

	return 0;
}


/*********************
Welcomes the user
*********************/
void welcome() 	//ran at the beginning of the program
{
	cout << "\n\n\n\n\n\nWelcome to the Exploring Oregon Program!\n\n";
	cout << "In this program, you will add activities that you can do in Oregon.\n";
	cout << "You will be able to add local activities and search for ones you \n";
	cout << "want to explore based on how far you want to travel.\n";
	cout << "And you can always look at all of them!\n";

	return;
}


/*********************
Gets the number of activities that can be added
*********************/
int get_size()	//get the max size for the number of activities
{	
	int size;	//local size
	cout << "\nLet us get started.  How many items do you wish to add? ";
	cin >> size;

	return size;	//returns the size or max num of activities to add
}

/*********************
Displays the options for the user 
*********************/
int display_options()
{
	int option;	//used to capture which optin the user wants

	cout << "\n\nMenu Options\n\n";
	cout << "1.  Add a new activity.\n";
	cout << "2.  Search for an activity close to Portland.\n";
	cout << "3.  Display all activities.\n";
	cout << "99.  Quit the Program.\n\n";
	cout << "Please enter the number of which option you want: ";
	cin >> option;	//grabs the local variable
	cin.ignore(100,'\n');

	return option;	//returns which variable the user wants
}

/*********************
Switch for user to input the option to choose from
*********************/
void switch_option(Manager & a_list)	//passes in info from the manager class
{
	int option = 0; 	//this variable is used for the user to select an option
	int miles = 0;		//declared this outside of switch
	do
	{
		option = display_options();	//display the options to the user
		switch(option){
			case 1:
				a_list.New_Activity();	//add a new activity
				break;
			case 2:
				cout << "How many miles from Portland do you want to search?\n";
				cin >> miles;			//user's miles to search 
				cin.ignore(100,'\n');
				a_list.Display_Area(miles);	//display the activities within the search
				break;
			case 3:
				a_list.Display_All();	//display all of the activities
				break;
			case 99:
				cout << "\nThank you for using the program.\n";
				break;
			default:
				cout << "\nInvalid Input.\n";
		}
	} while(option != 99);	//99 for user to quit
	
	return;
}


