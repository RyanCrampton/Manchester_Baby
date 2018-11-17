#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

enum Operands {JMPCODE, JRPCODE, LDNCODE, STOCODE, SUBCODE, SUB2CODE, CMPCODE, STPCODE};

class Baby {
private:
  vector<string> STORE;
  string ACCUMULATOR;
  //set CI to point to the default line 0
  string CI;
  string PI;
  bool debug;

public:
  Baby () { //default constructor
    //set ACCUMULATOR to be 0 for default
    ACCUMULATOR = "00000000000000000000000000000000";
    //set CI to point to the default line 0
    CI = "00000";
    //set current line to contain nothing at default
    PI = "00000000000000000000000000000000";
    debug = false;

  }
  //Baby (arguments);
  virtual ~Baby () {}

  void setStore() {
    this->STORE = loadFile();

  }


  vector<string> loadFile()
  {
    	//open the file in read mode
  	FILE *pFile;
  	pFile = fopen("Binary.txt", "r");

    vector<string> binaries;

  	//free(buffer);
    	if (pFile == NULL)
    	{
        //return and empty vector
  		return binaries;
  	}


  	size_t i, c;
  	char data;
  	i = c = 0;
  	//Determine how big the Array is going to be for memory allocation purposes
  	while ((data = fgetc(pFile)) != EOF)
  	{
      	if (data != '\n') {
        	i++;
  	    }
  	    else
  	    {
  	    	c++;
  	    }
    	}
  	int rows = c;
  	//don't need to cast to a float as this will always be a whole number
  	int columns = i/c;

    if (columns > 33 || rows > 33) {
      cerr << "ERR: File is bigger than 32x32" << '\n';
      return binaries;
    }

    	i = c = 0;
    	//rewind the file pointer to the first value
    	rewind(pFile);
      string currentLine;

    	while ((data = fgetc(pFile)) != EOF)
    	{

      	if (data == '\n')
      	{
        		i++;
        		c = 0;
            binaries.push_back(currentLine);
            currentLine.clear();
      	}
      	else
      	{
        	//set the array to the data in the file
  	    	currentLine.push_back(data);
      	}
    }

    fclose(pFile);
    return binaries;
  }

  /*
  	This function takes in an array and compares it to the various legal operations
  	then returns a number based on which opCode matches
  	@instruction - the current instruction sent it, to be calculated what number it
  	relates to
  	@return - A number from 0-7 based on the relevant opCodes
  */
  int getOpcode(string instruction)
  {
  	//int compare;
    //enum Operands {JMPCODE, JRPCODE, LDNCODE, STOCODE, SUBCODE, SUB2CODE, CMPCODE, STPCODE};
  	string opCodes[8] =
  	{
  		{"000"},
  		{"001"},
  		{"010"},
  		{"011"},
  		{"100"},
  		{"101"},
  		{"110"},
  		{"111"},
  	};

  	for (int i = 0; i < 8; i++) {

  		if (instruction.compare(opCodes[i]) == 0) {
        //cout << "Opcode: " << opCodes[i] << " Matches " << instruction << " at :" << i << '\n';
  			return i;
  		}
  	}
  	return -1;

  }

  /*
  	This method increments the global binary array CI by a single digit, it uses a basic for
  	loop to check which values are 0s or 1s
  */
  void incriment()
  {
   	int i = 0;

  	if (CI.at(i) == '1') {
  		do {
  			CI[i] = '0';

  		} while(CI[++i] != '0');

  		CI[i] = '1';

  	} else {
  		CI[i] = '1';
  	}


    //cout << "CURRENT INSTRICTION : " << CI << " NUMBER: " << binaryToDecimal(5, CI) << '\n';

  }

  void fetch() {

    int lineNumber = binaryToDecimal(5, CI);

    this->PI.clear();

    this->PI = this->STORE.at(lineNumber);
  }


  /*
  	This method pulls the relevant information from the lines of code, this pulls all of the needed info from the already established CI.
  	@param operand - This is the method that works with the location itself
  	@param instruction- This is the passed varible that holds the location that the command needs to go and also the command itself, this copies from the array
  */
  string decodeOperand () {
    return PI.substr(0, 5);
  }

  string decodeOpcode() {
    return PI.substr(13, 3);
  }

    void JMP(string operand)
    {
      printf("JMP \n");

      //this->CI = operand;
    }

    /*
    	This adds the content of the store location to the CI
    */
    void JRP(string operand)
    {
    	printf("JRP \n");

      int location1, location2, result;

      //location1 = binaryToDecimal(5, operand);
      //location2 = binaryToDecimal(5, this->CI);

      //result = location1 + location2;

      //this->CI = decimalToBinary(5, result);

    }
    /*
    	This gives the negative alternative of the content in the store and loads that in
    */
    void LDN()
    {
    	printf("LDN \n");
    }
    /*
    	This adds the contents of the Accumulator to the store
    */
    void STO()
    {
    	printf("STO \n");
    }
    /*
    	This subtracts the contents of the accumulator
    */
    void SUB()
    {
    	printf("SUB \n");
    }
    /*
    	if the accumulator has negative values then incriment, if it doesnt, then do nothing
    */
    void CMP()
    {
    	printf("CMP \n");
    }
    /*
    	This stops the proccess
    */
    void STP()
    {
    	printf("stopping \n");
    }


  /*
  	This method takes the input that the system has detected from the user and turns that into a command, this is passed on by the system through the fetch decode execute cycle
  	@param instruction - This the the instruction code the user has gained from the file
  	@param line - This code is the line that the code is to affect, this varies depending, it is converted from binary and passed on.
  */
  int execute(string instruction, string operand)
  {

    //cout << instruction << "      " << operand << '\n';

    //cout << instruction << '\n';

  	int opCode = getOpcode(instruction);

  	if(opCode == JMPCODE)
  	{
  		JMP(operand);
  	}
  	else if(opCode == JRPCODE)
  	{
  		JRP(operand);
  	}
  	else if(opCode == LDNCODE)
  	{
  		LDN();
  	}
  	else if(opCode == STOCODE)
  	{
  		STO();
  	}
  	else if(opCode == SUBCODE)
  	{
  		SUB();
  	}
  	else if(opCode == SUB2CODE)
  	{
  		SUB();
  	}
  	else if(opCode == CMPCODE)
  	{
  		CMP();
  	}
  	else if(opCode == STPCODE)
  	{
  		STP();
      return -1;
  	}
    return 0;
  }

  /* The following function takes in an integer array of 1's and 0's and converts
  the array into its Integer equivalent. It uses the powers of 2 for each 'bit'
  in the array to multiply it out then increments the current power of two.
  @size - The size argument is how many elements are in the array passed in (usually 32)
  @arrayToConvert - The arrayToConvert argument is the array to be converted to a Integer
  @return - returns the respective integer that is the result of the arrayToConvert
  */
  size_t binaryToDecimal(int size, string arrayToConvert) {

     int i;
     int decimal = 0, bit = 1;

     reverse(arrayToConvert.begin(), arrayToConvert.end());

     for (i = size - 1; i >= 0; i--) {

         decimal += (arrayToConvert[i] - '0')*bit;
         bit *= 2;
     }

  	 return decimal;
  }

  /*
  	The method below takes the input and changes that to a binary input, this will take an int and convert it
  	This takes a calculation and applies binary logic, checking for each interval of number it fits, getting a remainder then
  	passing that on
  	@size - This is the size of the item itself, this varies with how many are passed to the system
  	@numToConvert - This is the number being passed in that is about to be converted
  	@return - returns the completed binary number in an array
  */
  string decimalToBinary(int size, int numToConvert) {

  	string binary;
  	int k;

  	for (int i = size-1; i >= 0; i--) {

  		k = numToConvert >> i;

  		if (k & 1) {
  			binary.push_back('1');
  		} else {
  			binary.push_back('0');
  		}
  	}

    reverse(binary.begin(), binary.end());

    return binary;
  }
};

int main(int argc, char const *argv[]) {
  Baby *currentBaby = new Baby();

  currentBaby->setStore();

  int result = 0;

  while (result != -1) {
    currentBaby->incriment();

    currentBaby->fetch();
    result = currentBaby->execute(currentBaby->decodeOpcode(), currentBaby->decodeOperand());
    //cout << '\n' << result << '\n';

    }


  /*
  vector<string> testing;

  currentBaby->setStore();



  //currentBaby->execute("000"); //should ouput JMP


  int num = 7;

  string binary = currentBaby->decimalToBinary(32, num);

  cout << binary << '\n';

  std::cout << currentBaby->binaryToDecimal(32, binary) << '\n';
  */
  return 0;
}
