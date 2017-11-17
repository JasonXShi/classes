#include "digitalMedia.h"
#include <cstring>
#include <iostream>
using namespace std;
//making constructor
DigitalMedia::DigitalMedia(char* newTitle, int newYear) {
  title = newTitle;
  year = newYear;
}
//making getters
char* DigitalMedia::getTitle(){
  return title;
}

int DigitalMedia::getYear(){
  return year;
}
//making destructor
DigitalMedia::~DigitalMedia() {
  delete []title;
}
//prints out info
void DigitalMedia::displayInfo(){
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
}
//returns type
int DigitalMedia::getType(){
  return 0;
}
