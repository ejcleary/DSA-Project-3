//
// Created by ejcle on 4/26/2024.
//

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


#ifndef DSA_PROJECT_3_SORTS_H
#define DSA_PROJECT_3_SORTS_H




//Quick Sort helper functions
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int split(vector<pair<string, int>> unsortedvect, int low, int high) {
    int pivot = unsortedvect[low].second; // select the rightmost element as pivot
    int up=low, down=high;

    while(up<down){
        for (int j = up; j < high; j++) {   // move up continuously until you find an element greater than pivot
            if (unsortedvect[up].second > pivot)
                break;
            up++;
        }
        for (int j = high; j > low; j--){   // move down continuously until you find an element less than pivot
            if(unsortedvect[down].second < pivot)
                break;
            down--;
        }
        if(up<down) {
            swap(&unsortedvect[up].second, &unsortedvect[down].second);
        }
    }
    swap(&unsortedvect[low].second, &unsortedvect[down].second);
    return down;
}

//Main Quick Sort Method
vector<pair<string, int>> quickSort(vector<pair<string, int>> unsortedvect, int low, int high) {
    if (low < high){
        int pivot = split(unsortedvect, low, high);    // find pivot element such that element smaller than pivot are on the left and greater on the right
        quickSort(unsortedvect, low, pivot - 1);
        quickSort(unsortedvect, pivot + 1, high);
    }
    return unsortedvect;
}


//Merge Sort helper functions
void merge(vector<pair<string, int>> &unsortedvect, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<pair<string,int>> X(n1);
    vector<pair<string,int>> Y(n2);

    for (int i = 0; i < n1; i++) {  // copy data to X and Y
        X[i] = unsortedvect[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Y[j] = unsortedvect[mid + 1 + j];
    }

    int i, j, k;    // merge the two temporary arrays back into the original array
    i = 0, j = 0, k = left;

    while (i < n1 && j < n2){   // while elements in X and Y remain, compare the elements of X and Y
        if (X[i].second <= Y[j].second){
            unsortedvect[k] = X[i];
            i++;
        }
        else{
            unsortedvect[k] = Y[j];
            j++;
        }
        k++;
    }

    while (i < n1){ // When we run out of elements in either X or Y append the remaining elements
        unsortedvect[k] = X[i];
        i++;
        k++;
    }

    while (j < n2){
        unsortedvect[k] = Y[j];
        j++;
        k++;
    }
}

//Main Merge Sort function
vector<pair<string, int>> mergeSort(vector<pair<string, int>> &unsortedvect, int left, int right) {
    if (left < right){
        int mid = left + (right - left) / 2;    // m is the point where the array is divided into two subarrays

        mergeSort(unsortedvect, left, mid);
        mergeSort(unsortedvect, mid + 1, right);

        merge(unsortedvect, left, mid, right);
    }
    return unsortedvect;
}


#endif //DSA_PROJECT_3_SORTS_H
