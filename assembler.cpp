/*
	Assembler Program
	AC21009(CW3) - Manchester Baby - Group 16
	Ryan Crampton
	Liam Stewart
	Ross Maider
	Daniel Blackley
	Brenyn Goodwin
*/

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <bitset>

using namespace std;

string fileToBeCoded[256];

int negativeValue = -1;

string assemblyInstructions[13][3] = {
{"VAR", "Yes", "NULL"},
{"JMP", "Yes", "0000"},
{"JRP", "Yes", "1000"},
{"LDN", "Yes", "0100"},
{"STO", "Yes", "1100"},
{"SUB", "Yes", "0010"},
{"CMP", "No", "0110"},
{"STP", "No", "1110"},
{"ADD", "Yes", "0001"},
{"MUL", "Yes", "0101"},
{"DIV", "Yes", "0011"},
{"MVT", "Yes", "1111"},
{"MVF", "Yes", "0111"},
};

string newFileToBeCoded = "Output.txt"; //for passing to Simulator

//only uses the code file for now(will be able to take in extra programs
int loadCodeFile(string file)
{

	//open a file input stream using the file name passed into the function
	ifstream inputFile(file);

	//if the program cannot find the file then
	if(!inputFile)
	{
		//display an error to the user
		cout << "There was an error! The program cannot open the file." << endl;
		return 1;
		
	}

	string line;
	
	int iterateLine = 0;

	int ignoreValue = 0;

	//while loop searches through each line of code in the file to make sure it is not null
	while(getline(inputFile, line))
	{
		//ignore value variable is set to the value of not null
		ignoreValue = line.find_first_not_of("\n \t");
		
		//if the character at the start of the line is a ; then it can be ignored as it is a comment
		if(line.at(ignoreValue) != (';'))
		{
			//checks the line to see if there is a space in it before adding to the code file
			if(iterate < 256)
			{
				//the line is then stored in the code file and the negationValue value is increased
				fileToBeCoded[iterateLine] = line;
				iterate++;
				cout << "The current line has been added to the text file\t" << line << endl;
				negativeValue++;
			}
			else
			{
				//if the memory store is full then an error message is displayed
				cout << "There was an error! You are trying to add to a full memory store" << endl;
				return 1;
			}
		}
	}

	//closes the file stream
	inputFile.close();

	return 0;
}


int main()
{
	//create a new strng for any error messages
	string error = "";
	string file;

	cout << "Please enter a file name.\n";
	cin >> file;
	
	//call and run the loadCodeFile function
	loadCodeFile(file);

	return 0;
}