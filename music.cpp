#include <cstring>
#include "music.h"
#include <iostream>
using namespace std;

Music::Music(char* newTitle, int newYear, char* newArtist, char* newPublisher, int newDuration ) : DigitalMedia(newTitle, newYear){
  artist = newArtist;
  publisher = newPublisher;
  duration = newDuration;
}

char* Music::getArtist(){
  return artist;
}

char* Music::getPublisher(){
  return publisher;
}

int Music::getDuration(){
  return duration;
}
Music::~Music(){
  delete[] publisher;
  delete[] artist;
}
void Music::displayInfo(){
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Artist " << getArtist() << endl;
  cout << "Publisher: " << getPublisher() << endl;
  cout << "Duration: " << getDuration() << endl;
}

int Music::getType(){
  return 2;
}
