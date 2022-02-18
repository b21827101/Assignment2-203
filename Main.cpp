#include "ClassReading.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ofstream myFile;

int main(int argc, char** argv) {
    strcpy (ClassReading::commands,argv[1]);  //commands
    strcpy (ClassReading::output,argv[2]);    //output
    myFile.open(argv[2]);
    ClassReading class1;
    class1.main();
    myFile.close();
    return 0;
}

