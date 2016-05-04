/*
Jonathan Sweeney, CS162, Prog 5, 12/6/15
The purpose of the program is to allow the user to add activities near Portland 
and search for them.
*/

#include "activity.h"

/******************
This is the constructor for the object event
******************/
Event::Event() 
{
	name = NULL;
	description = NULL;
	location = NULL;
	miles = 0;
	notes = NULL;
}

/************************
This is the deconstructor
************************/
Event::~Event() 
{
	delete [] name;
	delete [] description;
	delete [] location;
	miles = 0;
	delete [] notes;
}						

/************************
Display's the information for each activity
************************/
void Event::Display() 
{
	cout << "The activity is named: " << name << endl;
	cout << "The description is: " << description << endl;
	cout << "The location is: " << location << endl;
	cout << "The miles are: " << miles << endl;
	cout << "The activity notes are: " << notes << endl;

	return;
}

/************************
This sets all of the information
************************/
void Event::Set(char * i_name, char * i_desc, char * i_loc, int i_miles, char * i_notes) //passing in input info and copies
{
	name = new char[strlen(i_name)];
	strcpy(name, i_name);

	description = new char[strlen(i_desc)];
	strcpy(description, i_desc);

	location = new char[strlen(i_loc)];
	strcpy(location, i_loc);

	miles = i_miles;

	notes = new char[strlen(i_notes)];
	strcpy(notes, i_notes); 

	return;
}

/************************
This boolean is used to determine which activities are 
within the user's input of miles
************************/
bool Event::Comp_miles(int input_miles) //passes in the num of miles the user inputs
{
	if(input_miles >= miles)
		return true;
	return false;
}	

/************************
This is the manager
************************/
Manager::Manager()
{
	index = 0;
	size = 0;
	array = NULL;
	head = NULL;

}	

/************************
This is the data structure manager
************************/
Manager::Manager(int i_size)
{
	index = 0;
	size = i_size;
	array = new Event[i_size];
	head = NULL;
}			

/************************
This is the deconstructor for manager
************************/
Manager::~Manager()
{
	index = 0;
	size = 0;
	delete [] array;
	array = NULL;
	delete_lll();
}

/************************
Where the user inputs new activities
************************/
void Manager::New_Activity()
{
	char i_name[MAX], i_desc[DESC], i_loc[MAX], i_notes[DESC];
	int i_miles;

	if(index < size) //if the user tries adding too much, then they can add
	{

	cout << "Please enter the activity's name: ";
	cin.get(i_name, MAX, '\n');
	cin.ignore(100, '\n');

	cout << "Please enter the description: ";
	cin.get(i_desc, DESC, '\n');
	cin.ignore(100, '\n');

	cout << "Please enter the activity's location: ";
	cin.get(i_loc, MAX, '\n');
	cin.ignore(100, '\n');

	cout << "Please enter the number of miles from Portland: ";
	cin >> i_miles;
	cin.ignore(100, '\n');

	cout << "Please enter any additional notes: ";
	cin.get(i_notes, DESC, '\n');
	cin.ignore(100, '\n');


		array[index].Set(i_name, i_desc, i_loc, i_miles, i_notes);

		++index;
	} else
	{
		cout << "Sorry there isn't room to add any additional activities.\n\n";
	}
	return;
}	

/************************
Displays true results for activities within num of miles
************************/
void Manager::Display_Area(int miles) //passes in the number of miles to search
{
	cout << "Your search results are: \n";
 	int count = 0;					  //used to check if there are any activities

	 for(int i = 0; i < index; ++i)	
	 {
	 	if(array[i].Comp_miles(miles))
	 	{
	 		++count;	
	 		array[i].Display();
	 	}
	 }
	 
	 if(count == 0)					//used to display if nothing is found within num of miles
	 	cout << "No results found within " << miles << " miles of Portland.\n";

	 cout << endl << endl;

	 return;
}	

/************************
Display all function
************************/
void Manager::Display_All()
{
	if(index == 0)	//if there aren't any activities added yet, display the 1st message
	{
		cout << "Sorry, no activities are added yet.\n\n";
	} else {
		cout << "Here are all of your activities: \n\n";

		build();

		display_lll(head);

		delete_lll();
	}
		cout << endl << endl;
}	


/************************
Build the lll
************************/

void Manager::build() 
{
	for(int i = 0; i < index; ++i)
		{
			insert(&array[i]);	
		}
}


/************************
Build the lll
************************/
void Manager::display_lll(node * head) 
{
	if(!head)
		return;
	head->data->Display();
	cout << endl;
	display_lll(head->next);

}

/************************
Build the lll
************************/
void Manager::delete_lll()
{
	if(!head)
		return;
	else {
		node * hold = head;
		while(head)
		{
			hold = head->next;
			delete head;
			head = hold;
		}
		head = NULL;
	}


}

/************************
Build the lll
************************/
void Manager::insert(Event * to_add)
{
	if(!head)	//if empty
	{
		head = new node;
		head->data= to_add;
		head->next = NULL;
	} else {		//there's stuff
		node * curr = head;
		node * prev = head;
		node * temp = new node;
		temp->data= to_add;
		temp->next = NULL;

		while(curr && curr->data->compare_name(to_add)<0) 	//while string compare & traverse
		{
			prev = curr;
			curr=curr->next;
		}
		if(prev == curr)
		{
			if(curr->data->compare_name(to_add)<0)		
			{
				head->next = temp;
			} else {
				temp->next = head;
				head = temp;
			}
		} else if(!curr) {
			prev->next = temp;	
		} else {
			temp->next = curr;
			prev->next = temp;
		}

	}

}


/************************
Compares the names in list and and the pointer 
************************/
int Event::compare_name(Event * to_add) 
{
	return strcmp(name,to_add->name);
}



