#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <tuple>

using namespace std;

//Code to read files inspired by geeksforgeeks

void readDriverFile() {  //reads the contents of the driver files and returns
unordered_map<string,tuple<string, string, string>> driversMap;
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
driversFile.close();
}

void readRacesFile() {  //reads the contents of the racers files and returns
unordered_map<string,tuple<string, string, string>> racesMap;

ifstream racersFile("racers.csv");
string line;

while (getline(racersFile, line)) {
    stringstream ss(line);
    string id, year, round, name;
    getline(ss, id, ',');
    getline(ss, year, ',');
    getline(ss, round, ',');
    getline(ss, name, ',');
    drivers[id] = make_tuple(year, round, stoiname);
}
racersFile.close();
}

void readLapTimeFile(){
    unordered_map<string,tuple<int, int, int>> lapTimeMap;
    //Inspired by geeksforgeeks

    ifstream lapTimeFile("tap_times.csv");
    string line;

    while (getline(lapTimeFile, line)) {
        stringstream ss(line);
        string raceID, driverID, val1, val2, val3;
        getline(ss, raceID, ',');
        getline(ss, driverID, ',');
        getline(ss, val1, ',');
        getline(ss, val2, ',');
        getline(ss, val3, ',');
        string keyVal = raceID + driverID;
        lapTimeMap[keyVal] = make_tuple(stoi(val1), stoi(val2), stoi(val3));
        //Process data and store in map
    }
    lapTimeFile.close();
}

