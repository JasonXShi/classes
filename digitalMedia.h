//header guards and includes
#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H
#include <cstring>

class DigitalMedia{
	public:
	//defining destructor, getters, and constructor.
	//also other functions like displayInfo and getType
	  DigitalMedia(char* newTitle, int newYear);
	  virtual ~DigitalMedia();
	  char* getTitle();
	  int getYear();
	  void displayInfo();
	  virtual int getType();
	private: //variables that are used in all the child classes
	  char* title;
	  int year;
};

#endif
