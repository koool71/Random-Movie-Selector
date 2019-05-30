#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <vector>
#include <time.h>
#include <sstream>

using namespace std;

// GLOBALS
vector<string> movies;
void mainMenu();
fstream list ("movieList.txt");

// Generates a random number used to select movie from list 
int random(int x, int y){
	srand(time(NULL));
	return (rand() % (y - x) + x);
}

// Updates the file the list lives at whenever there's a change made 
void writeList(){
	string line;
	if(list.is_open()){
		for(unsigned int i = 0; i < movies.size() - 1; ++i){
			list << movies[i] << "\n";
		}
		list << movies[movies.size()-1];
		list.close();
	}
}

// Initializes the starting list from a provided text file
void initList(){
	string line;
	if(list.is_open()){
		while(getline(list, line)){
			movies.push_back(line);
		}
		list.close();
	}
}

// Adds a movie to the movie list
void addMovie(){
	string newMovie;
	cout << "\nWhat movie would you like to add?" << endl;
	getline(cin, newMovie);
	movies.push_back(newMovie);
	list.open("movieList.txt", ios::out | ios::trunc);
	writeList();
	mainMenu();
}

// Selects a movie from the movie list at random and asks the user if thy would like to watch the movie or not
// If the users says they will watch the movie the movie will be deleted from the list
// If the user says they will not watch the movie it will bring them back to the main menu to either try again or 
// 	take another action
void chooseMovie(){
	string input;
	int movieSelection = random(0, movies.size());
	cout << "\n" << movies[movieSelection] << endl;
	cout << "Enter 1 if you will watch. Enter anything else to cancel" << endl;
	getline(cin, input); 
	if(input == "1"){
		movies.erase(movies.begin() + movieSelection);
		cout << "Enjoy the movie! It has now been deleted from your list" << endl;
		list.open("movieList.txt", ios::out | ios::trunc);
		writeList();
	} 	
	mainMenu();
}

// Prints the existing movie list
void printList(){
	cout << endl;
	for(unsigned int i = 0; i < movies.size(); ++i){
		cout << movies[i] << endl;
	}
	mainMenu();
}

// Main Menu giving the user options 
void mainMenu(){
	string input;
	cout << "\nRANDOM MOVIE MAIN MENU\nEnter 1 to add a movie\nEnter 2 to select a movie\nEnter 3 to see your list of movies\nEnter 'Quit' to quit" << endl;
	cout << "Enter here: ";
	getline(cin, input);
	if(input == "1"){
		addMovie();
	}
	else if (input == "2"){
		chooseMovie();
	}
	else if(input == "3"){
		printList();
	}
	else if(input[0] == 'q' || input[0] == 'Q'){
		return;
	}
	else{
		cout << "No. That is not a good reply. Please don't mess up again." << endl;
		mainMenu();
	}
}

// Initializes the movie list via input text file
// Begins the program by calling the Main Menu
int main(){
	initList();
	mainMenu();
	

	return 0;
}
