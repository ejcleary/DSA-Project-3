#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <tuple>
#include <set>
#include <vector>

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
unordered_map<string,pair<string, string>> racesMap;

ifstream racersFile("racers.csv");
string line;

while (getline(racersFile, line)) {
    stringstream ss(line);
    string id, year, round, name;
    getline(ss, id, ',');
    getline(ss, year, ',');
    getline(ss, round, ',');
    getline(ss, name, ',');
    racesMap[year+round] = make_pair(id, name);
}
racersFile.close();
}


void readLapTimeFile(){
    unordered_map<string,vector<tuple<int, int, int>>> lapTimeMap;
    set<pair<string,string>> RaceIDDriverIDPairs;
    unordered_map<string,vector<string>> RaceIDDriverIDMap;
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


vector<pair<string,int>> raceResuls(int year, int round){   //this function will return a vector of pairs. pairs of driver info and thier final position
    string raceID = racesMap[year+round].first; //getting the raceID

    vector<string> driversInRace;   //vector of all driversIDs in the race
    for(auto keyValPair : RaceIDDriverIDMap){       //populate vector
        driversInRace.push_back(keyValPair.second);
    }

    int numLaps = lapTimeMap[driversInRace[0]+raceID].size();  //getting number of laps so I can only evaluate that lap
    vector<pair<string, int>> finalVect;    //creating the return vector

    for(int i = 0; i < driversInRace.size(); i++){
        int position = get<2>(lapTimeMap[raceID + driversInRace[i]][numLaps-1]);
        string firstName = get<0>(driversMap[driversInRace[i]]);
        string lastName = get<1>(driversMap[driversInRace[i]]);
        string number = get<3>(driversMap[driversInRace[i]])
        string driverInfo = number + "|" + firstname + " " + lastName;
        finalVect.push_back(make_pair(driverInfo, position));
    }
    return finalVect;
}