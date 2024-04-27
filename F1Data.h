#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <map>
#include <string>
#include <tuple>
#include <set>
#include <vector>
#include <utility>
using namespace std;

class Formula1Data {
    private:

    map<string,tuple<string, string, string>> driversMap;
    map<string,pair<string, string>> racesMap;
    map<string,vector<pair<string, string>>> racesInYearMap;
    map<string,vector<tuple<int, int, int>>> lapTimeMap;
    map<string,vector<string>> RaceIDDriverIDMap;

public:
    void readDriverFile();
    void readRacesFile();
    void readLapTimeFile();

    void printRaces(string year);
    vector<pair<string,int>> raceResults(string year, string round);
    vector<pair<string,int>> fastestLaps(string year, string round);
};