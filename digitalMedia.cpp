#include "digitalMedia.h"
#include <cstring>
#include <iostream>
using namespace std;

DigitalMedia::DigitalMedia(char* newTitle, int newYear) {
  title = newTitle;
  year = newYear;
}

char* DigitalMedia::getTitle(){
  return title;
}

int DigitalMedia::getYear(){
  return year;
}

DigitalMedia::~DigitalMedia() {
  delete []title;
}

void DigitalMedia::displayInfo(){
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
}

int DigitalMedia::getType(){
  return 0;
}
