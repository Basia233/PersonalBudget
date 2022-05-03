#ifndef XMLFile_H
#define XMLFile_H

#include <iostream>
#include <fstream>

using namespace std;

class XMLFile
{
    const string FILENAME;

public:
    XMLFile(string filename) : FILENAME(filename) {}

     string getFilename();

};

#endif
