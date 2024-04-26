/*
//from lecture slides
#ifndef DSA_PROJECT_3_SORT_METHODS_H
#define DSA_PROJECT_3_SORT_METHODS_H

#include <iostream>
using namespace std;

//Quick Sort helper functions
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int split(int array[], int low, int high) {
    int pivot = array[low]; // select the rightmost element as pivot
    int up=low, down=high;

    while(up<down){
        for (int j = up; j < high; j++) {   // move up continuously until you find an element greater than pivot
            if (array[up] > pivot)
                break;
            up++;
        }
        for (int j = high; j > low; j--){   // move down continuously until you find an element less than pivot
            if(array[down]<pivot)
                break;
            down--;
        }
        if(up<down) {
            swap(&array[up], &array[down]);
        }
    }
    swap(&array[low], &array[down]);
    return down;
}

//Main Quick Sort Method
void quickSort(int array[], int low, int high) {
    if (low < high){
        int pivot = split(array, low, high);    // find pivot element such that element smaller than pivot are on the left and greater on the right
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}


//Merge Sort helper functions
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int X[n1], Y[n2];

    for (int i = 0; i < n1; i++) {  // copy data to X and Y
        X[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Y[j] = arr[mid + 1 + j];
    }

    int i, j, k;    // merge the two temporary arrays back into the original array
    i = 0, j = 0, k = left;

    while (i < n1 && j < n2){   // while elements in X and Y remain, compare the elements of X and Y
        if (X[i] <= Y[j]){
            arr[k] = X[i];
            i++;
        }
        else{
            arr[k] = Y[j];
            j++;
        }
        k++;
    }

    while (i < n1){ // When we run out of elements in either X or Y append the remaining elements
        arr[k] = X[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = Y[j];
        j++;
        k++;
    }
}

//Main Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right){
        int mid = left + (right - left) / 2;    // m is the point where the array is divided into two subarrays

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


#endif //DSA_PROJECT_3_SORT_METHODS_H
*/
