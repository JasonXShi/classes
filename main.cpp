/*
Allows the user to make a library of digital media -music, videogames, and movies
10/16/17
By: Jason Shi
*/
#include "digitalMedia.h"
#include "digitalMedia.cpp"
#include "videogame.h"
#include "videogame.cpp"
#include "movie.h"
#include "movie.cpp"
#include "music.h"
#include "music.cpp"
#include <cstring>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

int main(){
//makes the vector of digitalMedia that all the child classes can also use
  vector<DigitalMedia*> medias;
  while (true){
//display instructions
    cout << "Enter 'ADD' to Add Media" << endl;
    cout << "Enter 'DELETE' to Delete an item" << endl;
    cout << "Enter 'SEARCH' to Search for Objects in the Database" << endl;
    cout << "Enter 'QUIT' to exit the program" << endl;
	  //prompt for command input
    char input[7];
    cout << "Please Enter a command: "<<endl;
    cin.getline(input, 7);
    if (strcmp(input, "ADD") == 0){
	    //if they want to add media, make the user enter the info that is inherited for all
      char mediaType[10];
      char *title = new char[150];
      int year;
      cout << "Please enter the Type of Media (VIDEOGAME, MOVIE, MUSIC):"<<endl;
      cin.getline (mediaType, 10);
      cout << "Please Enter the Title:" << endl;
      cin.getline (title, 150);
      cout << "Enter the Year:"<< endl;
      cin >> year;
      cin.get();
      if (strcmp(mediaType, "VIDEOGAME") == 0){
	//allow input for the info for a videogame 
	char *publisher = new char[50];
	float rating;
	cout << "Enter the Name of the Publisher:" << endl;
	cin.getline (publisher, 50);
	cout << "Enter the Rating: " << endl;
	
	cin >> rating;
	cin.get();
	      //add it to the vector of digitalMedia
	VideoGame* temp = new VideoGame(title, year, publisher, rating);
	medias.push_back(temp);
      } else if (strcmp(mediaType, "MOVIE") == 0){
	      //enter all the info for a movie
	char *director = new char[50];
	int duration;
	float rating;
	cout << "Enter the Name of the Director of the Movie:"<< endl;
	cin.getline(director, 50);
	cout << "Enter the Duration of the Movie in Minutes: "<< endl;
	cin >> duration;
	cin.get();
	cout << "Enter the Rating of the Movie (1-5 Stars): " <<endl;
	cin >> rating;
	cin.get();
	      //add the movie to the vector of digitalMedia
	Movie* temp = new Movie(title, year, director, duration, rating);
	medias.push_back(temp);
      } else if (strcmp(mediaType, "MUSIC") == 0){
	//get all the info of music
	      char *artist = new char[50];
	int duration;
	char *publisher = new char[50];
	
	cout << "Enter the name of the Artist: " <<endl;
	cin.getline(artist, 50);
	cout << "Enter the Duration of the Song (in seconds): " <<endl;
	
	cin >> duration;
	cin.get();
	cout << "Enter the Publisher: " << endl;
	cin.getline(publisher, 50);
	      //add the music to the vector of digitalMedia
	Music* temp = new Music(title, year, artist, publisher, duration);
	medias.push_back(temp);
      } else {
	      //let them enter another command if they mess up
	cout << "Invalid media type.." <<endl;
	continue;
      }
    } else if(strcmp(input, "SEARCH") == 0){
	    //prompt for which method of searching
      cout << "Search by Title or Year? (Enter 'TITLE' or 'YEAR' [without the ']): " << endl;
      char *searchField = new char[6];
      cin.getline(searchField, 6);
	    //create iterator 
      vector<DigitalMedia*>::iterator it;
      int count = 0;
      if (strcmp(searchField, "TITLE")==0) {
	char *searchTitle = new char[150];
	      //prompt for the title to search
	cout << "Please Enter the title you want to search: " << endl;
	cin.getline(searchTitle, 150);	
	      //iterate through the vector and check if the title matches
	for(it = medias.begin(); it != medias.end(); it++) {
		//if the title matches, call the displayInfo method to print the info
	  if (strcmp((*it)->getTitle(), searchTitle)==0) {
	    switch((*it)->getType()) {
	    case 1  : //movie
	      ((Movie*)(*it))->displayInfo();
	      break;
	    case 2  : //music
	      ((Music*)(*it))->displayInfo();
	      break;
	    default : //VideoGame
	      ((VideoGame*)(*it))->displayInfo();
	    }
	    count++;
	  }
	}
	
	//printf("Found total of %d Digital Media with TITLE %s. \n", count, searchTitle);
      }
      else if (strcmp(searchField, "YEAR")==0){
	      //if the user wants to search by year, prompt for the year
	int searchYear;
	cout << "Please enter the year you want to search: " << endl;
	cin >> searchYear;
	cin.get();
	      //iterate through the vector and if the year matches print out the info using displayinfo()
	for(it = medias.begin(); it != medias.end(); it++) {
	  if ((*it)->getYear()==(searchYear)) {
	    switch((*it)->getType()) {
	    case 1  : //movie
	      ((Movie*)(*it))->displayInfo();
	      break;
	    case 2  : //music
	      ((Music*)(*it))->displayInfo();
	      break;
	    default : //VideoGame
	      ((VideoGame*)(*it))->displayInfo();
	    }
	    count++;
	  }
	}
	//printf("Found total %d Digital Medias with YEAR %s. \n", count, searchYear);
      }
      else {
	      //if they don't enter TITLE or YEAR allow them to retry 
	cout << "Invalid Search Field" << endl;
	continue;
      }
      
    } else if(strcmp(input, "DELETE")==0){
	    //allow them to choose to delete with the title or the year
      cout << "Delete by Title or Year? (Enter 'TITLE' or 'YEAR' [without the ']): " << endl;
	    //initialize variables 
      char *deleteField = new char[6];
      char *confirm = new char[2];
      cin.getline(deleteField, 6);
	    //create iterator
      vector<DigitalMedia*>::iterator it;
      int count = 0;
      if (strcmp(deleteField, "TITLE")==0) {
	      //get the title to be deleted inputed
	char *deleteTitle = new char[150];
	cout << "Please enter the title you want to delete: " << endl;
	cin.getline(deleteTitle, 150);
	      //iterate and if the title matches, print out the info
	for ( it = medias.begin(); it != medias.end(); ){
	  if (strcmp((*it)->getTitle(),deleteTitle)==0) {
	    //print out info
	    switch((*it)->getType()) {
	    case 1  : //movie
	      ((Movie*)(*it))->displayInfo();
	      break;
	    case 2  : //music
	      ((Music*)(*it))->displayInfo();
	      break;
	    default : //VideoGame
	      ((VideoGame*)(*it))->displayInfo();
	    }
	    //confirm if the user wants to delete
	    cout << "Do you wish to delete this? (Enter 'Y' for yes or 'N' for no [without the '])";
	    cin.getline(confirm, 2);
		  //delete the digitalMedia (auto calls the deconstructor)
	    if(strcmp(confirm, "Y")==0){
	      delete * it;
	      it = medias.erase(it);
	    }else if (strcmp(confirm, "N")==0){
	      ++it;
	    }else{
	      cout << "Not valid entry..";
	      ++it;
	      break;
	    }
	    count++;
	  }
	  else {
	    ++it;
	  }
	}
	//printf("Deleted total %d Digital Medias with TITLE %s. \n", count, deleteTitle);
      }
      else if (strcmp(deleteField, "YEAR")==0){
	      //ask user to input the year of the digitalMedia to be deleted
	int deleteYear;
	cout << "Please enter the year you want to delete: " << endl;
	cin >> deleteYear;
	cin.get();
	int index = 0;
	      //iterate through vector and if the year matches, print out info using displayInfo()
	for ( it = medias.begin(); it != medias.end(); ){
	  if ((*it)->getYear()==(deleteYear)) {
	     //print out info
	    switch((*it)->getType()) {
	    case 1  : //movie
	      ((Movie*)(*it))->displayInfo();
	      break;
	    case 2  : //music
	      ((Music*)(*it))->displayInfo();
	      break;
	    default : //VideoGame
	      ((VideoGame*)(*it))->displayInfo();
	    }
	    //confirm if the user wants to delete
	    cout << "Do you wish to delete this? (Y,N)";
	    cin.getline(confirm, 2);
		  //delete if they confirm
	    if(strcmp(confirm, "Y")==0){
	      delete * it;
	      it = medias.erase(it);
	    }else if (strcmp(confirm, "N")==0){
		    //skip over and keep iterating if they don't want to delete it
	      ++it;
	    }else{
	      cout << "Not valid entry..";
	      ++it;
	      break;
	    }
	    count++;
	  
	  }
	  else {
	    ++it;
	  }
	}
	//printf("Deleted total %d Digital Medias with YEAR %s. \n", count, deleteYear);
      }
      else {
	      //allows user to retry command if they enter an invalid one (in delete)
	cout << "Invalid Delete Field" << endl;
	continue;
      }
    } else if(strcmp(input, "QUIT") ==0){
      //end on quit
      break;
    } else{
	    //allows user to retry command if they enter an invalid one
      cout << "Not a valid option. ";
      continue;
    }
  }
}
