#include <fstream> 
#include <iostream> 
#include <string>
#include <unordered_map>

using namespace std;

void readDriverFile() {  //reads the contents of the driver files and returns
unordered_map<int,tuple<string, string, int> driverData> driversMap;

//Code to read file inspired by geeksforgeeks

ifstream driversFile("drivers.csv");
string line;

while (getline(driversFile, line)) {
    stringstream ss(line);
    string driverID, firstName, surName, number;
    getline(ss, driverID, ',');
    getline(ss, firstName, ',');
    getline(ss, surName, ',');
    getline(ss, number, ',');
    driversMap[driverID] = make_tuple(firstName, surName, number);
}
driversFile.close()
}



void readRacesFile() {  //reads the contents of the driver files and returns
unordered_map<int,tuple<string, string, int> driverData> racesMap;


//Code to read file inspired by geeksforgeeks

ifstream racersFile("racers.csv");
string line;

while (getline(racersFile, line)) {
    stringstream ss(line);
    string id, year, round, name;
    getline(ss, id, ',');
    getline(ss, year, ',');
    getline(ss, round, ',');
    getline(ss, name, ',');
    drivers[id] = make_tuple(year, round, name);
}
racersFile.close()
}



