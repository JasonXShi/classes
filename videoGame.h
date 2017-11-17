//make header guards and include 
#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "digitalMedia.h"
#include <cstring>

class VideoGame:public DigitalMedia{
 public:
 //defines the constructor and getters
  VideoGame(char* newTitle, int newYear, char* newPublisher, float newRating);
  char* getPublisher();
  float getRating();
 //defines the methods such as displaying info, getting type, and deconstructor
  void displayInfo();
  int getType();
  ~VideoGame();
 private:
 //the variables that are unique in a videogame
  char* publisher;
  float rating;
};

#endif
