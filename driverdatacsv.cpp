#include <fstream> 
#include <iostream> 
#include <string>
#include <unordered_map>

using namespace std;

void readDriverFile {
unordered_map<int,tuple<string, string, int> driverData>
//Inspired by geeksforgeeks

ifstream driversFile("drivers.csv");
string line;

while (getline(driversFile, line)) {
    stringstream ss(line);
    //Process data and store in map
}


driversFile.close()
}



