#include <stdio.h>
#include <stdlib.h>
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
decode()
{

}
int incriment()
{
	loadFile();
	
}
int fetch()
{

}
int decode()
{
	int instruction;
	int line;


	execute(instruction, line)
}
int execute(int instruction, int line)
{
	if(instruction == 0)
	{
		JMP();
	}
	else if(instruction == 1)
	{
		JRP();
	}
	else if(instruction == 2)
	{
		LDN();
	}
	else if(instruction == 3)
	{
		STO();
	}
	else if(instruction == 4)
	{
		SUB();
	}
	else if(instruction == 5)
	{
		SUB();
	}
	else if(instruction == 6)
	{
		CMP();
	}
	else if(instruction == 7)
	{
		STP();
	}
}
int display_everything()
{

}
int JMP()
{

}
int JRP()
{

}
int LDN()
{

}
int STO()
{

}
int SUB()
{

}
int CMP()
{

}
int STP()
{
	stopped = true;
}
int main()
{
	bool stopped = false;
	while(stopped == false)
	{
		incriment();
		fetch();
		decode();
		execute();
	}
	display_everything();
}
