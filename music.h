#ifndef MUSIC_H
#define MUSIC_H
#include "digitalMedia.h"
#include <cstring>

class Music:public DigitalMedia{
 public:
  Music(char* newTitle, int newYear, char* newArtist, char* newPublisher, int newDuration);
  char* getArtist();
  char* getPublisher();
  int getDuration();
  void displayInfo();
  int getType();
  ~Music();
 private:
  char* artist;
  char* publisher ;
  int duration;
};

#endif
