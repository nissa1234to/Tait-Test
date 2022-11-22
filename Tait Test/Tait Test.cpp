// Project: Tait Test
// Author: Nissa Absalom
// Last Modified: 22/11/2022
// File Description: 

// External Headers
// Provides access to things like console and file streams
#include <iostream>
#include <fstream>

// Provides handles writing to the JSON file
#include "JSON.h"

// Not best practice, but makes life easier
using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;

    cout << "Started\n";

    inputFile.open("test.txt");

    // Validate the input file was opened
    if (inputFile.fail())
    {
        cout << "failed to open input file\n";
        return -1;
    }

    outputFile.open("test.json");

    // Validate the output file was opened
    if (inputFile.fail())
    {
        cout << "failed to open output file\n";
        return -2;
    }

    // Run the JSON conversion and print number of objects written
    cout << "Objects written: " << writeJSON(&inputFile, &outputFile);

    // Be a tidy Kiwi
    inputFile.close();
    outputFile.close();
}
