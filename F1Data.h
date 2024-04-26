#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <tuple>
#include <set>
#include <vector>
#include <utility>
using namespace std;

class Formula1Data {
    private:
    int year;
    int round;
    unordered_map<string,tuple<string, string, string>> driversMap;
    unordered_map<string,pair<string, string>> racesMap;
    unordered_map<string,vector<pair<string, string>>> racesInYearMap;
    unordered_map<string,vector<tuple<int, int, int>>> lapTimeMap;
    unordered_map<string,vector<string>> RaceIDDriverIDMap;

public:
    void readDriverFile();
    void readRacesFile();
    void readLapTimeFile();

    void printRaces(int year);
    vector<pair<string,int>> raceResults(string year, string round);
    vector<pair<string,int>> fastestLaps(string year, string round);
};


