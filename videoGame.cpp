#include <cstring>
#include "videogame.h"
#include <iostream>
using namespace std;

VideoGame::VideoGame(char* newTitle, int newYear, char* newPublisher, float newRating) : DigitalMedia(newTitle, newYear){
  publisher = newPublisher;
  rating = newRating;
}

char* VideoGame::getPublisher(){
  return publisher;
}

float VideoGame::getRating(){
  return rating;
}

void VideoGame::displayInfo(){
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Publisher: " << getPublisher() << endl;
  cout << "Rating: " << getRating() << endl;
}

int VideoGame::getType(){
  return 3;
}
VideoGame::~VideoGame(){
  delete []publisher;
}
