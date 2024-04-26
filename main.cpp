
// Created by ejcle on 4/23/2024.
//test branch

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>
#include "F1Data.h"

using namespace std;

int main() {
    Formula1Data F1Info;
    //F1Info.readDriverFile();
    //F1Info.readRacesFile();
    //F1Info.readLapTimeFile();

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

    //F1Info.printRaces(to_string(year));

    cout << "Please select how you would like to view the data:" << endl;
    cout << "1. View Race Results" << endl;
    cout << "2. View Fastest Lap per Driver" << endl;
    cout << "3. View Driver Positions by Lap" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        auto quick_timer = chrono::high_resolution_clock::now();
        // quickSort();
        // View winner (sort total lap times per driver = race result)
        auto end_quick = chrono::high_resolution_clock::now();
        auto quick_duration = chrono::duration_cast<chrono::microseconds>(end_quick - quick_timer).count();
        cout << "Time taken by Quick Sort: " << quick_duration << " microseconds" << endl;

        auto merge_timer = chrono::high_resolution_clock::now();
        // mergeSort();
        // View winner (sort total lap times per driver = race result)
        auto end_merge = chrono::high_resolution_clock::now();
        auto merge_duration = chrono::duration_cast<chrono::microseconds>(end_merge - merge_timer).count();
        cout << "Time taken by Merge Sort: " << merge_duration << " microseconds" << endl;
        cout << "Results:" << endl;
        //print results of the sorting method
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




