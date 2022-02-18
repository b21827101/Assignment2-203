#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ClassReading.h"
#include "LibrarySystem.h"
#include <vector>
using namespace std;
extern ofstream myFile;

string strprev="null";
string strcurrent="null";
char ClassReading::commands[50];
char ClassReading::output[50];


void ClassReading::writingtitle() {  //if prev and current are same,not write anything
    if(strprev == "null"){
        myFile<<strcurrent<<"\n";

    }
    else if(strcurrent != strprev){
        myFile<<"\n"<<strcurrent<<"\n";
    }
    else if(strcurrent == strprev){
        return;
    }

}



void ClassReading::linemethod(string *commandarray,int length){  //for going to method
    LibrarySystem lib;
    lib.main();
    myFile<<"===Movie Library System===\n\n";

    for(int i =0;i<length;i++){

        if(commandarray[i].find("addUser")< commandarray[i].length()){
            istringstream iss(commandarray[i]);
            string s,userName,userName2;
            strcurrent = "===addUser() method test===";
            writingtitle();
            int userId;
            iss >> s>> userId>>userName>>userName2;
            userName += " " +userName2;
            lib.addUser(userId,userName);
            strprev = "===addUser() method test===";


        }
        else if(commandarray[i].find("deleteUser")< commandarray[i].length()){
            istringstream iss(commandarray[i]);
            string s;
            strcurrent = "===deleteUser() method test===";
            writingtitle();
            int userId;
            iss >> s>> userId;
            lib.deleteUser(userId);
            strprev =  "===deleteUser() method test===";
        }
       else if(commandarray[i].find("addMovie")< commandarray[i].length()){
            vector<string> result;
            string commands=commandarray[i];
            stringstream ss( commands);
            while(ss.good()) {   //using vector for split line
                string substr;
                getline(ss, substr, '\t'); //get first string delimited by comma
                result.push_back(substr);
            }
            stringstream ss1(result.at(1));
            ss1 << result.at(1);
            int movieId;
            ss1 >> movieId;
            stringstream ss2(result.at(3));
            ss2 << result.at(3);
            int year;
            ss2 >> year;
            strcurrent ="===addMovie() method test===";
            writingtitle();
            lib.addMovie(movieId	,result.at(2)	,year);
            strprev = "===addMovie() method test===";
        }
       else if(commandarray[i].find("deleteMovie")< commandarray[i].length()){
            istringstream iss(commandarray[i]);
            string s;
            strcurrent = "===deleteMovie() method test===";
            writingtitle();
            int userId;
            iss >> s>> userId;
            lib.deleteMovie(userId);
            strprev ="===deleteMovie() method test===";
       }
       else if(commandarray[i].find("checkoutMovie")< commandarray[i].length()){
            istringstream iss(commandarray[i]);
            string s;
            strcurrent = "===checkoutMovie() method test===";
            writingtitle();
            int movieId,userId;
            iss >> s>> movieId>>userId;
            lib.checkoutMovie(movieId,userId);
            strprev ="===checkoutMovie() method test===";
       }
       else if(commandarray[i].find("showAllMovie")< commandarray[i].length()){
            strcurrent ="===showAllMovie() method test===";
            writingtitle();
            lib.showAllMovies();
            strprev="===showAllMovie() method test===";
        }
       else if(commandarray[i].find("returnMovie")< commandarray[i].length()){
            istringstream iss(commandarray[i]);
            string s;
            strcurrent ="===returnMovie() method test===";
            writingtitle();
            int movieId;
            iss >> s>> movieId;
            lib.returnMovie(movieId);
            strprev="===returnMovie() method test===";
        }
       else if(commandarray[i].find("showMovie")< commandarray[i].length()){
            istringstream iss(commandarray[i]);
            string s;
            strcurrent ="===showMovie() method test===";
            writingtitle();
            int movieId;
            iss >> s>> movieId;
            lib.showMovie(movieId);
            strprev = "===showMovie() method test===";
       }
       else if(commandarray[i].find("showUser")< commandarray[i].length()){
            istringstream iss(commandarray[i]);
            string s;
            strcurrent ="===showUser() method test===";
            writingtitle();
            int userId;
            iss >> s>> userId;
            lib.showUser(userId);
            strprev ="===showUser() method test===";
       }
    }
}


void ClassReading::reading() {
    int count = 0;
    ifstream inFile1;
    inFile1.open(ClassReading::commands);//"commands3.txt"
    int j = 0;
    if (!inFile1) {

    }
    string str;
    while (getline(inFile1, str)) {
        count++;
    }
    inFile1.close();

    inFile1.open(ClassReading::commands);
    string commandsArray[count+1];

    while (getline(inFile1, str)) {
        commandsArray[j] = str;
        j++;
    }
    inFile1.close();
    linemethod(commandsArray,count+1);
}



int ClassReading::main(){
    reading();
    return 0;
}






