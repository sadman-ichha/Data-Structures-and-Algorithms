#include <iostream>
using namespace std;

int linearSearch(int nums[], int numsLength, int target) {
    int i, steps = 0;
    for (i = 0; i < numsLength; i += 1) {
        steps++;
        if (nums[i] == target) {
            cout << "Steps taken by Linear: " << steps << endl;
            return i;  // Return the index if the target is found
        }
    }

    cout << "Steps taken by Linear: " << steps << endl;
    return -1;  // Return -1 if the target is not found
}

int main() {
    int nums[] = {8, 11, 2, 5, 7, 15, 19, 20};
    int numsLength = sizeof(nums) / sizeof(nums[0]);
    int target;
    cout << "Your Target Number: ";
    cin >> target;
    int result = linearSearch(nums, numsLength, target);

    if (result != -1)
        cout << "Element found at Index: " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}

// Space Complexity: O(1) (constant space used for variables)
// Time Complexity: O(n) (linear time complexity due to sequential search through the array)
