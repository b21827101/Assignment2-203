
#ifndef UNTITLED1_CLASSREADING_H
#define UNTITLED1_CLASSREADING_H
#include <string>
using namespace std;

class ClassReading {
public:
    int main();
    void linemethod(string *commandarray,int length);
    void reading();         //reading commands txt
    void writingtitle();   //writing txt titles

    static char commands[50];
    static char output[50];
};

#endif //UNTITLED1_CLASSREADING_H
