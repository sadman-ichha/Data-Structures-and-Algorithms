#include <iostream>
using namespace std;

int binarySearch(int nums[], int numsLength, int target) {
    int low, high, mid, steps;
    low = 0;
    high = numsLength - 1;
    steps = 0;

    while (low <= high) {
        steps++;
        mid = (high + low) / 2;

        if (nums[mid] == target) {
            cout << "Steps taken by Binary: " << steps << endl;
            return mid; // Return the index if the target is found
        } else if (nums[mid] < target)
            low = mid + 1; // If target is greater, ignore the left half
        else
            high = mid - 1; // If target is smaller, ignore the right half
    }

    cout << "Steps taken by Binary: " << steps << endl;
    return -1; // Return -1 if the target is not found
}

int main() {

    int nums[] = {2, 4, 5, 8, 9, 11, 16, 28, 40};
    int numsLength = sizeof(nums) / sizeof(nums[0]);
    int target;
    cout << "Your Target Number: ";
    cin >> target;
    int result = binarySearch(nums, numsLength, target);

    if (result == -1)
        cout << "Element not found in the array." << endl;
    else
        cout << "Element Found at index: " << result << endl;

    return 0;
}
