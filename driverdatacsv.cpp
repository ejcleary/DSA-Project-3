#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <tuple>
#include <set>
#include <vector>
#include <utility>
#include "F1Data.h"

using namespace std;

//Code to read files inspired by geeksforgeeks

void Formula1Data::readDriverFile() {  //reads the contents of the driver files and returns
//unordered_map<string,tuple<string, string, string>> driversMap;
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


void Formula1Data::readRacesFile() {  //reads the contents of the racers files and returns
//unordered_map<string,pair<string, string>> racesMap;

ifstream racersFile("racers.csv");
string line;

while (getline(racersFile, line)) {
    stringstream ss(line);
    string id, year, round, name;
    getline(ss, id, ',');
    getline(ss, year, ',');
    getline(ss, round, ',');
    getline(ss, name, ',');
    racesInYearMap[year].push_back(make_pair(round, name));
    racesMap[year+round] = make_pair(id, name);
}
racersFile.close();
}


void Formula1Data::readLapTimeFile(){
    //unordered_map<string,vector<tuple<int, int, int>>> lapTimeMap;
    set<pair<string,string>> RaceIDDriverIDPairs;
    //unordered_map<string,vector<string>> RaceIDDriverIDMap;
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
        lapTimeMap[keyVal].push_back(make_tuple(stoi(val1), stoi(val2), stoi(val3)));
        //Process data and store in map
        RaceIDDriverIDPairs.insert(make_pair(raceID, driverID));
    }
    lapTimeFile.close();

    for(auto pair : RaceIDDriverIDPairs){
        RaceIDDriverIDMap[pair.first].push_back(pair.second);
    }
}

vector<pair<string,int>> Formula1Data::raceResults(string year, string round){   //this function will return a vector of pairs. pairs of driver info and thier final position
    string raceID = racesMap[year+round].first; //getting the raceID

    vector<string> driversInRace;   //vector of all driversIDs in the race
    for(int j = 0; j < RaceIDDriverIDMap[raceID].size(); j++){       //populate vector
        driversInRace.push_back(RaceIDDriverIDMap[raceID][j]);
    }

    int numLaps = lapTimeMap[driversInRace[0]+raceID].size();  //getting number of laps so I can only evaluate that lap
    vector<pair<string, int>> finalVect;    //creating the return vector

    for(int i = 0; i < driversInRace.size(); i++){
        int position = get<1>(lapTimeMap[raceID + driversInRace[i]][numLaps-1]);
        string firstName = get<0>(driversMap[driversInRace[i]]);
        string lastName = get<1>(driversMap[driversInRace[i]]);
        string number = get<2>(driversMap[driversInRace[i]]);
        string driverInfo = number + "|" + firstName + " " + lastName;
        finalVect.push_back(make_pair(driverInfo, position));
    }
    
    return finalVect;
}

vector<pair<string,int>> Formula1Data::fastestLaps(string year, string round){  //returns a vector of a single drivers lap times
    string raceID = racesMap[year+round].first; //getting the raceID

    vector<string> driversInRace;   //vector of all driversIDs in the race
    for(int j = 0; j < RaceIDDriverIDMap[raceID].size(); j++){       //populate vector
        driversInRace.push_back(RaceIDDriverIDMap[raceID][j]);
    }

    int numLaps = lapTimeMap[driversInRace[0]+raceID].size();  //getting number of laps so I can only evaluate that lap
    vector<pair<string, int>> finalVect;    //creating the return vector

    for(int i = 0; i < driversInRace.size(); i++){
        int lapTime;
        int fastestLap = INT_MAX;
        for(int k = 0; k < numLaps; k++) {
            lapTime = get<2>(lapTimeMap[raceID + driversInRace[i]][k]);
            if(lapTime <= fastestLap) {
                fastestLap = lapTime;
            }
        }
        string firstName = get<0>(driversMap[driversInRace[i]]);
        string lastName = get<1>(driversMap[driversInRace[i]]);
        string number = get<2>(driversMap[driversInRace[i]]);
        string driverInfo = number + "|" + firstName + " " + lastName;
        finalVect.push_back(make_pair(driverInfo, fastestLap));
    }
    return finalVect;
}

void Formula1Data::printRaces(string year) {
    //For a given year, print all the races in order
    for (auto pair : racesInYearMap[year]) {
        cout << "Race " << pair.first << ":" << pair.second << endl;
    }
}