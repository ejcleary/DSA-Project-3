
// Created by ejcle on 4/23/2024.
//test branch

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>
#include "F1Data.h"
#include "sorts.h"
#include <map>

using namespace std;

int main() {
    Formula1Data F1Info;
    F1Info.readDriverFile();
    F1Info.readRacesFile();
    F1Info.readLapTimeFile();

    //load all csv files
    cout << "Welcome to the Formula 1 Database!" << endl;
    cout << "Please select a year [2015-2024]:" << endl;
    int year;
    cin >> year;
    if (year < 2015 || year > 2024) {
        cout << "The year entered is not in range." << endl;
        return -1;
    }
    cout << "Please select a race:" << endl;

    F1Info.printRaces(to_string(year));

    string round;
    cin >> round;

    cout << "Please select how you would like to view the data:" << endl;
    cout << "1. View Race Results" << endl;
    cout << "2. View Fastest Lap per Driver" << endl;
    cout << "3. View Driver Positions by Lap" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {

        vector<pair<string, int>> unsortedvect = F1Info.raceResults(to_string(year), round);
        int low = 0;
        int high = unsortedvect.size()-1;
        for(auto pair : unsortedvect){
            cout << pair.second  << " " << pair.first << endl;
        }

        auto quick_timer = chrono::high_resolution_clock::now();
        vector<pair<string, int>> sortedvect;
        quickSort(unsortedvect, low ,high);
        // View winner (sort total lap times per driver = race result)
        auto end_quick = chrono::high_resolution_clock::now();
        auto quick_duration = chrono::duration_cast<chrono::microseconds>(end_quick - quick_timer).count();
        cout << "Time taken by Quick Sort: " << quick_duration << " microseconds" << endl;

        auto merge_timer = chrono::high_resolution_clock::now();
        sortedvect = mergeSort(unsortedvect, low ,high);
        // View winner (sort total lap times per driver = race result)
        auto end_merge = chrono::high_resolution_clock::now();
        auto merge_duration = chrono::duration_cast<chrono::microseconds>(end_merge - merge_timer).count();
        cout << "Time taken by Merge Sort: " << merge_duration << " microseconds" << endl;
        cout << "Results:" << endl;

        for(auto pair : sortedvect){
            int finalPosition = pair.second;
            string driverInfo = pair.first;
            if(finalPosition < 1 || finalPosition > 20){
                cout << "DNF" << " ";
            }
            else{
                cout << finalPosition  << " ";
            }
            cout << driverInfo << endl;
        }
    }




    if (choice == 2) {
        string driverId, raceId;
        cout << "Please enter the driver ID: ";
        cin >> driverId;
        cout << "Please enter the race ID: ";
        cin >> raceId;
        // View the fastest lap (sort the fastest lap times per driver)
        // input driver id and specific race id

        auto quick_timer = chrono::high_resolution_clock::now();
        //quickSort();
        auto end_quick = chrono::high_resolution_clock::now();
        auto quick_duration = chrono::duration_cast<chrono::microseconds>(end_quick - quick_timer).count();
        cout << "Time taken by Quick Sort: " << quick_duration << " microseconds" << endl;

        auto merge_timer = chrono::high_resolution_clock::now();
        //mergeSort();
        auto end_merge = chrono::high_resolution_clock::now();
        auto merge_duration = chrono::duration_cast<chrono::microseconds>(end_merge - merge_timer).count();
        cout << "Time taken by Merge Sort: " << merge_duration << " microseconds" << endl;
        cout << "Results:" << endl;
        //print results of the sorting method
    }
};




