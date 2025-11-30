/*
 * insultgenerator.cpp
 *
 *  Created on: Sep. 24, 2021
 *      Author: Isabel Frolick
 */



#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <set>
#include <random>
#include <algorithm>

#include "insultgenerator.h"

using namespace std;


/*
need  initialize() method - load all the source phrases from the InsultsSource.txt file into attributes
							uses vector<string> as insults attribute in main() is a vector<string>
	 	 	 	 	 	 	  - if file can't be read- throw FileException
	 	 	 	 	 	 	  - return type is void(), takes in no parameters
 */

void InsultGenerator::initialize(){
																		//load the first words into the first vector<string>
	fstream Insults;													//create file type 'Insults' with input and output functionality
	Insults.open("insultgenerator.txt");								//load source file into Insults
	string word; 														//create local attributes for method to provide functionality
	int whichColumn;
	int i = 1;
	srand(time(NULL));													//use srand() to improve randomization by setting an initial point for rand()

	if(!Insults.is_open()){												//check if file can be opened
		throw FileException();											//if it can't, throw exception (will return error message)
		return;
	}
	while(Insults>>word){ 												//while there's insults in the source file to be read into a string
		whichColumn = i%3; 												//take the modulus of 3- to seperate the insults into 3 columns
		switch(whichColumn){											//will return 0,1, or 2
		case 1:															//push the insult in the first column into the vector<string> column1
			column1.push_back(word);									//column1, 2, 3 are private vector<string> attributes of InsultGenerator class
			break;
		case 2:
			column2.push_back(word); 									//put into column 2
			break;
		case 0:
			column3.push_back(word); 									//put into column 3
			break;
		}
		i++;															//run through all insults until there are no new insults in the source file
	}
	return;
}



//need talkToMe() method    - returns a single insult- generated at random
string InsultGenerator::talkToMe(){

	int x = rand() % 50;												//take random modulus of any of the 50 insults in each column
	int y = rand() % 50;
	int z = rand() % 50;

	string first = column1[x]; 											//save the insult at the location randomly generated in the vector<string>
	string second = column2[y];											//into a temp string variable- one for each insult to be randomly generated
	string third = column3[z]; 											//parse into string for output

	string oneInsult = "Thou " + first + " " + second + " " + third  + "!";


	return oneInsult;													 //return string of 3 randomly generated insults
}


/*
 * need generate() method    - generate the requested number of unique slots-
							 - so when an object calls ig.generate(100)- produces 100 insults
 *
 */
vector<string> InsultGenerator::generate(int genInsults){
	vector<string> insults; 											//create local attribute insults (vector of strings)


	if(genInsults < 0 || genInsults > 10000){							//set bounds, must be a positive integer, less than or equal to 10000
		throw NumInsultsOutOfBounds();									//else throw error message for bounds
	}

	for(int i =0; i < genInsults; i++){ 								//set up loop to iterate through all indices of insults to produce the number of insults that were called
		insults.push_back(talkToMe());									//for each iteration, call talkToMe() to produce random strings- then save into vector<string> for output using psuh_back function
	}

	return insults; 													//return  vector<string>
}

/*
 *
 *	need generateAndSave() method- produces a vector<string> of the number of insults requested
 *								- creates new file of the name given in input
 *								- saves in alphabetical order with no duplicates in one insult

 */

void InsultGenerator::generateAndSave(const string& fileName, int insultsRequested){

	fstream myFile;															//create new file
	myFile.open(fileName, fstream::out); 									//open new file for output under the file name provided in main()

	if(!myFile.is_open()){													//check if file is open, if it's not throw an exception
		throw FileException();
		return;
	}

	if(insultsRequested < 0 || insultsRequested > 10000){					//check if the number of insults requested to be produced is within the possible bounds
		throw NumInsultsOutOfBounds();
		return;
	}
																			//use generate() method to produce a vector of strings object Insults of he size requested in main()
	vector<string> Insults = generate(insultsRequested);					//sort each insult produced by the first insult in the list for alphabetical order
	sort(Insults.begin(), Insults.end());									//there will never be duplicates in one insult because all items are unique to one column vector<string>
																			//and each insult only uses one insult from each column
	for(int i = 0; i <= insultsRequested; i++){								//use for loop to iterate through the requested number of insults
		myFile << Insults[i] << endl;										//output each insult produced to the file created in alphabetical order, without duplicates
	}

	myFile.close();															//always close file for proper syntax
	return;

}



