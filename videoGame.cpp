//includes useful code
#include <cstring>
#include "videogame.h"
#include <iostream>
using namespace std;
//constructor for videogame, also calls the constructor of digitalMedia for the title and year
VideoGame::VideoGame(char* newTitle, int newYear, char* newPublisher, float newRating) : DigitalMedia(newTitle, newYear){
  publisher = newPublisher;
  rating = newRating;
}
//making getters
char* VideoGame::getPublisher(){
  return publisher;
}

float VideoGame::getRating(){
  return rating;
}
//prints out info
void VideoGame::displayInfo(){
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Publisher: " << getPublisher() << endl;
  cout << "Rating: " << getRating() << endl;
}
//returning 0 for a videoGame
int VideoGame::getType(){
  return 0;
}
//destructor for videogame, deletes the pointer of publisher
VideoGame::~VideoGame(){
  delete []publisher;
}
