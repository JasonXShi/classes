//includes needed code
#include <cstring>
#include "music.h"
#include <iostream>
using namespace std;
//constructor for music, also calls the constructor of the parent class (digitalMedia)
Music::Music(char* newTitle, int newYear, char* newArtist, char* newPublisher, int newDuration ) : DigitalMedia(newTitle, newYear){
  artist = newArtist;
  publisher = newPublisher;
  duration = newDuration;
}
//makes getters
char* Music::getArtist(){
  return artist;
}

char* Music::getPublisher(){
  return publisher;
}

int Music::getDuration(){
  return duration;
}
//destructor: deletes the pointers
Music::~Music(){
  delete[] publisher;
  delete[] artist;
}
//displays the info of music
void Music::displayInfo(){
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Artist " << getArtist() << endl;
  cout << "Publisher: " << getPublisher() << endl;
  cout << "Duration: " << getDuration() << endl;
}
//returns '2' if it is music
int Music::getType(){
  return 2;
}
