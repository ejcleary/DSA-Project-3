//from lecture slides
#ifndef DSA_PROJECT_3_SORT_METHODS_H
#define DSA_PROJECT_3_SORT_METHODS_H

#include <iostream>
using namespace std;

//QUICK SORT
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) {
    // select the rightmost element as pivot
    int pivot = array[low];
    int up=low, down=high;

    // while up is less than down
    while(up<down){
        // move up continuously until you find an element greater than pivot
        for (int j = up; j < high; j++){
            if(array[up]>pivot)
                break;
            up++;
        }
        // move down continuously until you find an element less than pivot
        for (int j = high; j > low; j--){
            if(array[down]<pivot)
                break;
            down--;
        }
        // if up is less than down, swap the elements at up and down
        if(up<down) {
            swap(&array[up], &array[down]);
        }
    }
    // swap pivot with the element at down
    swap(&array[low], &array[down]);
    return down;
}

void quickSort(int array[], int low, int high) {
    if (low < high){
        // find pivot element such that element smaller than pivot are on the left and greater on the right
        int pivot = partition(array, low, high);
        // recursively call quicksort on the two subarrays
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}


//MERGE SORT
void merge(int arr[], int left, int mid, int right) {
    // create two temporary arrays X and Y
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int X[n1], Y[n2];

    // copy data to X and Y
    for (int i = 0; i < n1; i++) {
        X[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Y[j] = arr[mid + 1 + j];
    }

    // merge the two temporary arrays back into the original array
    int i, j, k;
    i = 0, j = 0, k = left;

    // while elements in X and Y remain, compare the elements of X and Y
    while (i < n1 && j < n2){
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
    // When we run out of elements in either X or Y append the remaining elements
    while (i < n1){
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

void mergeSort(int arr[], int left, int right) {
    if (left < right){
        // m is the point where the array is divided into two subarrays
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted subarrays
        merge(arr, left, mid, right);
    }
}


#endif //DSA_PROJECT_3_SORT_METHODS_H
