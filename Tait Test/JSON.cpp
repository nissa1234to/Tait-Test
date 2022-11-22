// Project: Tait Test
// Author: Nissa Absalom
// Last Modified: 22/11/2022
// File Description: Parses txt files to JSON

// Header for this file
#include "JSON.h"

void writePair(char* pairData, size_t length, ofstream* outputFile, bool final)
{
	// Write two tabs for formatting
	outputFile->write("\t\t", 2);

	// Write the name-value pair
	outputFile->write(pairData, length);

	// If this is the final name-value pair don't write a comma
	if (final)
	{
		// Write newline for formatting
		outputFile->write("\n", 1);
	}
	else
	{
		// Write newline for formatting and comma
		outputFile->write(",\n", 2);
	}
}

void writeObject(char* objectLine, ofstream* outputFile)
{
	char* pairData = objectLine;
	char* pairDataEnd = objectLine;

	// Flag to determine if pairDataEnd currently points to a char that is inside quotes
	bool inQuotes = false;

	// Open object
	outputFile->write("\t{\n", 3);

	// Loop untill the null char is hit
	while (*pairDataEnd != '\0')
	{

		// If a comma is hit write the name-value pair located between this comma and the previous one
		if ((*pairDataEnd == ',') && (!inQuotes))
		{
			writePair(pairData, pairDataEnd - pairData, outputFile, false);

			pairDataEnd++;
			pairData = pairDataEnd;
		}

		// Ensures that a comma inside of quotes is treated like any other char
		if (*pairDataEnd == '"')
			inQuotes = !inQuotes;

		pairDataEnd++;
	}

	// Write the final name-value pair
	writePair(pairData , pairDataEnd - pairData, outputFile, true);

	// Close object
	outputFile->write("\t}", 2);
}

int writeJSON(ifstream* inputFile, ofstream* outputFile)
{
	// Create array of char for storing the object in text form
	// Note: max line length is 1023 chars, this limit is arbitrary
	char objectLine[1024];

	size_t objectCount = 0;

	// Open array
	outputFile->write("[\n", 2);

	while (true)
	{
		inputFile->getline(objectLine, 1024);

		// Break out of loop if no lines remain to be read
		if (objectLine[0] == '\0')
			break;

		// If an object has previously been writen add a comma and new line for formatting
		if (objectCount > 0)
			outputFile->write(",\n", 2);

		writeObject(objectLine, outputFile);

		objectCount++;
	}

	// Close array
	outputFile->write("\n]", 2);

	return objectCount;
}