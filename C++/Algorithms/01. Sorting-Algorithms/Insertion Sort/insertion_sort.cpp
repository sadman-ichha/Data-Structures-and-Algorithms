#include <iostream>
using namespace std;

void insertionSort(int arr[], int n);

void printArray(int arr[], int n);

int main()
{
    int arr[] = {5, 6, 12, 11, 13};       // array declaration
    int n = sizeof(arr) / sizeof(arr[0]); // array length calculation
    cout << "Before Sorting: ";
    printArray(arr, n);
    insertionSort(arr, n);
    cout << "After Sorting: ";
    printArray(arr, n);
    return 0;
}

void insertionSort(int arr[], int n)
{
    int j, key, i;
    for (j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
