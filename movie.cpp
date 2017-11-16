#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;

Movie::Movie(char* newTitle, int newYear, char* newDirector, int newDuration, float newRating) : DigitalMedia(newTitle, newYear){
  director = newDirector;
  duration = newDuration;
  rating = newRating;
}

char* Movie::getDirector(){
  return director;
}

int Movie::getDuration(){
	return duration;
}

float Movie::getRating(){
  return rating;
}

void Movie::displayInfo(){
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Director: " << getDirector() << endl;
  cout << "Duration: " << getDuration() << endl;
  cout << "Rating: " << getRating() << endl;
}

int Movie::getType(){
  return 1;
}
Movie::~Movie(){
  delete[] director;
}
