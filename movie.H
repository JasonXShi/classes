#ifndef MOVIE_H
#define MOVIE_H
#include "digitalMedia.h"
#include <cstring>

class Movie:public DigitalMedia{
 public:
  Movie(char* newTitle,int newYear,  char* director, int duration, float newRating);
  int getDuration();
  char* getDirector();
  float getRating();
  void displayInfo();
  int getType();
  ~Movie();
 private:
  char* director;
  int duration;
  float rating;
};

#endif
