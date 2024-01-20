#include <iostream>
using namespace std;
void printArray(int arr[], int length);
void selectionSort(int arr[], int length);
int main()
{

    int arr[] = {12, 32, 25, 14, 24, 2, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Sorting: ";
    printArray(arr, length);
    selectionSort(arr, length);
    cout << "After Sorting: ";
    printArray(arr, length);

    return 0;
}

void selectionSort(int arr[], int length)
{
    int i, j, min_index, temp;
    for (i = 0; i < length; i++)
    {
        min_index = i;
        for (j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void printArray(int arr[], int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}