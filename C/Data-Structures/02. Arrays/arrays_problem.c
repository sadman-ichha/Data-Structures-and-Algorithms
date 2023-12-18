#include <stdio.h>

int main()
{
    int i, element, length, backward, abs, even, odd, sum = 0, temp_mini;
    int arr[10] = {5, 3, -4, 7, 10, 12, 11, -8, 15, 20};

    length = sizeof(arr) / sizeof(arr[0]); // Calculate the length of the array:
                                           // sizeof(arr) gives the total size of the array in bytes, 10*4 = 40 bytes
                                           // sizeof(arr[i]) gives the size of a single element in bytes, int = 4 bytes
                                           // dividing the total size by the size of one element gives the number of elements. 40/4 =10
    printf("Arrays Length= %d \n", length);
    printf("FORWARD PRINT : ");
    // Printng for Forward print
    for (i = 0; i < length; i += 1) // i++ is same i+=1
    {
        element = arr[i];
        printf("%d ", element);
    }
    printf("\n");

    // Printng for Backward print
    printf("BACKWARD PRINT: ");
    for (i = length - 1; i >= 0; i -= 1) // i-- is same i-=1
    {
        backward = arr[i];
        printf("%d ", backward);
    }

    printf("\n");

    // Printng for Absulate Value print
    printf("ABS VALUE PRINT: ");
    for (i = 0; i < length; i++)
    {
        abs = arr[i];
        if (abs < 0)
        {
            abs = abs * -1;
        }
        printf("%d ", abs);
    }

    printf("\n");

    // Printng for EVEN NUMBER
    printf("EVEN NUMBER PRINT: ");
    for (i = 0; i < length; i++)
    {
        even = arr[i];
        if (even % 2 == 0)
        {
            printf("%d ", even);
        }
    }

    printf("\n");

    // Printng for ODD NUMBER
    printf("ODD NUMBER PRINT: ");
    for (i = 0; i < length; i++)
    {
        odd = arr[i];
        if (odd % 2 != 0)
        {
            printf("%d ", odd);
        }
    }

    printf("\n");

    // Printng for SUM NUMBER
    printf("SUM NUMBER PRINT: ");
    for (i = 0; i < length; i++)
    {
        sum = sum + arr[i];
    }
    printf("%d ", sum);
    // printf("%.2f ", sum / length);

    printf("\n");

    // Printng for MINIMUN NUMBER
    printf("MINIMUN NUMBER PRINT: ");
    int min = arr[0];
    for (i = 0; i < length; i++)
    {
        temp_mini = arr[i];
        if (min > temp_mini)
        {
            min = temp_mini;
        }
    }
    printf("%d ", min);

    return 0;
}
