//makes the header guards and includes code
#ifndef MUSIC_H
#define MUSIC_H
#include "digitalMedia.h"
#include <cstring>

class Music:public DigitalMedia{
 public:
 //defines the constructor and getters
  Music(char* newTitle, int newYear, char* newArtist, char* newPublisher, int newDuration);
  char* getArtist();
  char* getPublisher();
  int getDuration();
 //defines the other functions -destructor, getting the type, and printing out the info
  void displayInfo();
  int getType();
  ~Music();
 private:
 //makes the variables that are unique to music
  char* artist;
  char* publisher;
  int duration;
};

#endif
