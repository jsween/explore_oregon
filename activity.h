/*
Jonathan Sweeney, CS162, Prog 5, 12/6/15
The purpose of the program is to allow the user to add activities near Portland 
and search for them.
*/

//Libraries
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//Constants
const int MAX = 31;		//max for for characters 
const int DESC = 151;	//max for longer descriptions



/************************
Event Object for activities
************************/
class Event 
{

	public:
		Event();	//default
		~Event();	//deconstructor					

		void Display();	//display an activity
		void Set(char * i_name, char * i_desc, char * i_loc, int i_miles, char * i_notes); //setting info that the user inputs
		bool Comp_miles(int input_miles);	//for searching within a num of miles

		int compare_name(Event * to_add); //compare strings

	private:		//all of the object's information
		char * name;		//name of the activity
		char * description; //description of activity
		char * location;	//location of activity
		int miles;			//miles from pdx
		char * notes;		//notes that the user adds

};

/************************
Struct to add a linear linked list
************************/
struct node {
	Event *data;
	node *next;
};

/************************
Manager for the data structure
************************/
class Manager
{
	public:
		Manager();						//default
		Manager(int i_size);			//constructor w/ size setting limit
		~Manager();						//deconstructor
		void New_Activity();			//get new activity and store it into an array
		void Display_Area(int miles);	//display activities in a radius based off miles
		void Display_All();				//display all activities
		void display_lll(node * head);			//display the lll
		void delete_lll();			//delete lll
		void insert(Event * to_add);	//insert data into lll

	private:
		int index;					//index of array... also used as a count
		int size;					//user determines the max
		Event * array;				//data structure

		node *head; 				//head pointer
		void build();				//build the lll
};


