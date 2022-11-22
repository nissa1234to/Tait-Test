// Project: Tait Test
// Author: Nissa Absalom
// Last Modified: 22/11/2022
// File Description: Header file for the JSON module of the Tait Test project.
// Provides inter-module access to the writeJSON method.

#pragma once // The best part of c++
#include <fstream>

using namespace std;

int writeJSON(ifstream* inputFile, ofstream* outputFile);
