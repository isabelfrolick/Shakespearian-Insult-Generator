/*
 * insultgenerator_18ijzf.h
 *
 *  Created on: Sep. 25, 2021
 *      Author: Isabel Frolick, 18ijzf
 */


//if not defined and define statement for complete syntax in header file

#ifndef INSULTGENERATOR_18IJZF_H_
#define INSULTGENERATOR_18IJZF_H_

//all libraries included in child files of this header file
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <algorithm>
#include <random>

//define classes, functions, global variables
//DECLARATIONS

using namespace std;


//class insultGenerator
class InsultGenerator{
public:
	InsultGenerator(){}; 													//default constructor to create object ig in main()
	void initialize(); 														//load all source phrases into the string array attributes, no params, return 1 if good, return 0 if there's an error
	string talkToMe(); 														//no param, returns string of 1 insult
	vector<string> generate(int genInsults);								//takes in number of insults to generate, returns strings
	void generateAndSave(const string& fileName, int insultsRequested); 	//takes in file name to write to, # of insults requested- returns string type

private:
	vector<string> column1, column2, column3; 								//one array for each of the 3 columns to choose randomly

};



//custom class- derived from exception class
class FileException: public std::exception { 								//outputs error message when file is not found
public:
	const char* what() const noexcept {
		return "WARNING! No file found.";
	}

};


//custom class- derived from exception class
//returns out of bounds error when an attempt to derive data from outside
class NumInsultsOutOfBounds : public std::exception{					//the bounds of the data structure is made in main()
public:
	const char* what() const noexcept{
		return "You're out of bounds.";
	}
};


#endif
