#include <iostream>
using namespace std;

// Function to partition the array and return the index of the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the pivot
    int i = low - 1; // Index of the smaller element

    // Iterate through the subarray to rearrange elements based on the pivot
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap elements smaller than the pivot to the left
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot in its correct position
    return i + 1; // Return the index of the pivot
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Get the index of the pivot
        // Recursively sort the subarrays on the left and right of the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 1, 10, 15, 17, 11};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    int low = 0, high = arrLength - 1;
    cout << "Original Array: ";
    printArray(arr, arrLength);
    quickSort(arr, low, high);
    cout << "Sorted Array: ";
    printArray(arr, arrLength);
    return 0;
}
