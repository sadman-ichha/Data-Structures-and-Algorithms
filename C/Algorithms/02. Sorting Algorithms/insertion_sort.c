#include <stdio.h>

void printArray(int arr[], int length); 

int main()
{
    int arr[] = {4, 2, 12, 5, 14, 8};
    int check_value, i, temp_empty;
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, length);

    for (i = 1; i < length; i++)
    {
        check_value = arr[i];
        temp_empty = i - 1;
        while (temp_empty >= 0 && arr[temp_empty] > check_value)
        {
            arr[temp_empty + 1] = arr[temp_empty];
            // temp_empty = temp_empty - 1;
            temp_empty--;
        }
        arr[temp_empty + 1] = check_value;
    }

    printf("Sorted array: \n");
    printArray(arr, length);

    return 0;
}

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
