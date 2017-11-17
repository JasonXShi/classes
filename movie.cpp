//includes needed stuff
#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;
//make constructor, it also calls the constructor of the parent class
Movie::Movie(char* newTitle, int newYear, char* newDirector, int newDuration, float newRating) : DigitalMedia(newTitle, newYear){
  director = newDirector;
  duration = newDuration;
  rating = newRating;
}
//makes getters
char* Movie::getDirector(){
  return director;
}

int Movie::getDuration(){
	return duration;
}

float Movie::getRating(){
  return rating;
}
//display the info of a movie
void Movie::displayInfo(){
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Director: " << getDirector() << endl;
  cout << "Duration: " << getDuration() << endl;
  cout << "Rating: " << getRating() << endl;
}
//return '1' if it is a movie
int Movie::getType(){
  return 1;
}
//destructor for movie
Movie::~Movie(){
  delete[] director;
}
