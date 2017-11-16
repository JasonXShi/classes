#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "digitalMedia.h"
#include <cstring>

class VideoGame:public DigitalMedia{
 public:
  VideoGame(char* newTitle, int newYear, char* newPublisher, float newRating);
  char* getPublisher();
  float getRating();
  void displayInfo();
  int getType();
  ~VideoGame();
 private:
  char* publisher;
  float rating;
};

#endif
