//header guards and includes
#ifndef MOVIE_H
#define MOVIE_H
#include "digitalMedia.h"
#include <cstring>

class Movie:public DigitalMedia{
 public:
 //defines constructor and getters
  Movie(char* newTitle,int newYear,  char* director, int duration, float newRating);
  int getDuration();
  char* getDirector();
  float getRating();
 //defines other functions like the destructor, displaying info, and getting the type
  void displayInfo();
  int getType();
  ~Movie();
 private:
 //makes the variables unique to movies
  char* director;
  int duration;
  float rating;
};

#endif
