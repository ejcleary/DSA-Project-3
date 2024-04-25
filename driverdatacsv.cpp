#include <fstream> 
#include <iostream> 
#include <string>
#include <unordered_map>

using namespace std;

void readDriverFile() {
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

