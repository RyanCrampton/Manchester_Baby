#include <stdio.h>
#include <stdlib.h>

int ACCUMULATOR[32] = {0,0,1,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//set CI to point to the default line 0
int CI[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int PI[32] = {0,0,1,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int stopped = 1;
enum Operands {JMPCODE, JRPCODE, LDNCODE, STOCODE, SUBCODE, SUB2CODE, CMPCODE, STPCODE};

int **loadFile() {
	/*
  printf("Please enter in the file name to be loaded\n");

	  //buffer holds the input from getLine
	  char *buffer;
	  buffer = (char *)malloc(32 * sizeof(char));
	  if( buffer == NULL)
	  {
	        printf("Malloc fail upon file load.\n");
	        return NULL;
	   }
	   fgets(buffer, 32, stdin);
		 */
  		//open the file in read mode
	  	FILE *pFile;
	  	pFile = fopen("Binary.txt", "r");

	 		//free(buffer);
  		if (pFile == NULL) {

    	return NULL;
  	}


  size_t i, c;
  char data;
  i = c = 0;
  //Determine how big the Array is going to be for memory allocation purposes
  while ((data = fgetc(pFile)) != EOF) {
    if (data != '\n') {
      i++;
    } else {
      c++;
    }
  }
  int rows = c;
  //don't need to cast to a float as this will always be a whole number
  int columns = i/c;


  int** boardToLoad = malloc((rows) * sizeof(int *));

  if (boardToLoad == NULL) {

    printf("Malloc fail, out of memory\n");
    return NULL;
  }

  for (i = 0; i < rows; i++) {

    boardToLoad[i] = (int *) malloc((columns) * sizeof(int));
    if (boardToLoad[i] == NULL) {

      printf("Malloc fail, out of memory\n");
      return NULL;
    }
  }

  i = c = 0;
  //rewind the file pointer to the first value
  rewind(pFile);

  while ((data = fgetc(pFile)) != EOF) {

    if (data == '\n') {

      i++;
      c = 0;
    } else {

      //set the array to the data in the file
      boardToLoad[i][c++] = data - '0';
    }
  }

  fclose(pFile);
  return boardToLoad;
}
/* The following function takes in an integer array of 1's and 0's and converts
the array into its Integer equivalent. It uses the powers of 2 for each 'bit'
in the array to multiply it out then increments the current power of two.

@size - The size argument is how many elements are in the array passed in (usually 32)
@arrayToConvert - The arrayToConvert argument is the array to be converted to a Integer

@return - returns the respective integer that is the result of the arrayToConvert
*/
int binaryToDecimal(int size, int arrayToConvert[]) {

   int i;
   int decimal = 0, bit = 1;
   for (i = size - 1; i >= 0; i--) {

       decimal += arrayToConvert[i]*bit;
       bit *= 2;
   }

	 return decimal;
}

void JMP()
{
	printf("JMP");
}
void JRP()
{
	printf("JRP");
}
void LDN()
{
	printf("LDN");
}
void STO()
{
	printf("STO");
}
void SUB()
{
	printf("SUB");
}
void CMP()
{
	printf("CMP");
}
void STP()
{
	printf("stopping");
	stopped = 0;
}

/*
This function takes in an array and compares it to the various legal operations
then returns a number based on which opCode matches

@instruction - the current instruction sent it, to be calculated what number it
relates to

@return - A number from 0-7 based on the relevant opCodes
*/
int getOpcode(int instruction[3]) {

	int compare;

	int opCodes[8][3] = {
		{0,0,0},
		{1,0,0},
		{0,1,0},
		{1,1,0},
		{0,0,1},
		{1,0,1},
		{0,1,1},
		{1,1,1},
	};


	for (int i = 0; i < 7; i++) {
		for (size_t c = 0; c < 3; c++) {
			if (instruction[c] != opCodes[i][c]) {
				break;
			}

			if (c == 2) {
				return i;
			}
		}
	}

	return -1;

}

void execute(int instruction[3], int line[5])
{

	int opCode = getOpcode(instruction);

	if(opCode == JMPCODE)
	{
		JMP();
	}
	else if(opCode == JRPCODE)
	{
		JRP();
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
	}
}
/*
This method increments the global binary array CI by a single digit, it uses a basic for
loop to check which values are 0s or 1s
*/
void incriment()
{
 	int i = 31;

	if (CI[i] == 1) {
		do {
			CI[i] = 0;
		} while(CI[--i] != 0);

		CI[i] = 1;

	} else {
		CI[i] = 1;
	}

}

/*
This function gets the address from the CI array by converting it from a binary to a decimal
then sets PI to be equal to the address in the file that Ci was referencing
*/
void fetch(int **currentFile)
{
	int address = binaryToDecimal(32, CI);

	for (size_t i = 0; i < 32; i++) {
		PI[i] = currentFile[address][i];
	}

}

void decode()
{
	int opCode[3];
	int operand[5];
  	int instruction[32];
  	for(int i = 0; i < 32; i++)
  	{
  		instruction[i] = CI[i];
  	}
	for(int i = 0; i <= 4; i++)
	{
    	//extract bits one through five from the instruction and insert them into the operand
    	operand[i] = instruction[i];
	}
	int lineCode[5];
	for(int i = 13; i<16; i++)
	{
		lineCode[i-13] = instruction[i];
	}
	//execute(opCode, operand);
}

int display_everything()
{
	for(int i = 0; i < 32; i++)
	{
		printf("test");
	}
	return 1;
}
int main()
{


	//testing the loadfile function
	int **currentFile = loadFile();

	for (size_t i = 0; i < 10; i++) {
		for (size_t c = 0; c < 32; c++) {
			printf("%d", currentFile[i][c]);
		}
		printf("\n");
	}


	/*

	while(stopped == 1)
	{
		incriment();
		fetch();
		decode();
		execute();
	}
	display_everything();
	*/
	//decode();

	//execute(test, testLine);

}
