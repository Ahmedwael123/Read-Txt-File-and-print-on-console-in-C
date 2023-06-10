#include <stdio.h>
#include <stdlib.h>

// Read_file Function to read the file
char *read_file (char *filename);



int main()
{
/* filename Variable to store the user input file name */
char filename[1024];

printf("File: ");
fflush(stdout);

/* The User enters the file name and stores it in filename */
scanf("%s",filename);

/* file_contents to get the returned string from read_file*/
char * file_contents=read_file (filename);

/* Check if file_contents gets the data from the read_file function */
if (file_contents == NULL)
{
	printf("ERROR READING FILE \n");

	return 1;



}

/* After Checking , print the file contents */
printf("File Contents:\n%s\n",file_contents);

/* To free the memory allocation*/
free(file_contents);

return 0;
}

char *read_file (char *filename)
{
	/* A variable to store the file */
	FILE *file;

	/* Open the file and store it in file*/
	file =fopen (filename, "r");

	/* Check if the file has the data and not empty*/
	if (file == NULL )
	{
		return NULL;
	}

	/* Move the pointer to the end of the file*/
	fseek (file ,0, SEEK_END);

	/* Get the length of the file*/
	int length= ftell(file);

	/* Return the pointer to the start of the file */
	fseek(file,0,SEEK_SET);

	/*  A string array with the length of the file*/
	char *string =malloc(sizeof(char)*(length+1));

	/* Variable to store characters of file in */
	char c;

	/* Counter to get all the file characters */
	int i=0;

	/* While loop to get all the characters */
	while ((c=fgetc(file)) != EOF)
	{

		/* store the characters in string */
		string [i]=c;
		/* increment i to get the next character */
		i++;
	}
	/* Store phi in the last one after storing the characters */
	string[i]='\0';

	/* To Close the file */
	fclose(file);

	/* Return the String containing the file contents */
	return string;
}
