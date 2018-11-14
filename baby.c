#include <stdio.h>
#include <stdlib.h>

int array[32] = {0,0,1,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int stopped = 1;

/*
char **loadFile() {
  printf("Please enter in the file name to be loaded\n");
	  fseek(stdin,0,SEEK_END);
	  //buffer holds the input from getLine
	  char *buffer;
	  buffer = (char *)malloc(32 * sizeof(char));
	  if( buffer == NULL) 
	  {
	        printf("Malloc fail, Out of memoy.\n");
	        return NULL;
	   }
	   fgets(buffer, bufsize, stdin);
	   return buffer;
  		//open the file in read mode
	  	FILE *pFile;
	  	pFile = fopen(fileName, "r";
	 	free(fileName);
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
  rows = c;
  //don't need to cast to a float as this will always be a whole number
  columns = i/c;
  char** boardToLoad = malloc((rows) * sizeof(char *));
  if (boardToLoad == NULL) {
    printf("Malloc fail, out of memory\n");
    return NULL;
  }
  for (i = 0; i < rows; i++) {
    boardToLoad[i] = (char *) malloc((columns) * sizeof(char));
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
      boardToLoad[i][c++] = data;
    }
  }
  fclose(pFile);
  return boardToLoad;
}
*/
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
void execute(int instruction[3], int line[5])
{
	int check[3] = {0,0,0};
	int check1[3] = {1,0,0};
	int check2[3]  = {0,1,0};
	int check3[3]  = {1,1,0};
	int check4[3]  = {0,0,1};
	int check5[3]  = {1,0,1};
	int check6[3]  = {0,1,1};
	int check7[3] = {1,1,1};

	if(instruction == check)
	{
		JMP();
	}
	else if(instruction == check1)
	{
		JRP();
	}
	else if(instruction == check2)
	{
		LDN();
	}
	else if(instruction == check3)
	{
		STO();
	}
	else if(instruction == check4)
	{
		SUB();
	}
	else if(instruction == check5)
	{
		SUB();
	}
	else if(instruction == check6)
	{
		CMP();
	}
	else if(instruction == check7)
	{
		STP();
	}
}
void incriment()
{
	//loadFile();
	
}
void fetch()
{
	int address[5];
}
void decode()
{
	int opCode[3];
	int operand[5];
  	int instruction[32]; 
  	for(int i = 0; i < 32; i++)
  	{
  		instruction[i] = array[i];
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
	execute(opCode, operand);
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
	decode();
	return 1;
}
