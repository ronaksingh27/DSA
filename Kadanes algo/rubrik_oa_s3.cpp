#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to implement Kadane's algorithm and return the maximum sum and start and end indices
tuple<int, int, int> kadane(const vector<int>& arr) {
    int max_sum = INT_MIN, current_sum = 0;
    int start = 0, end = 0, temp_start = 0;

    for (int i = 0; i < arr.size(); i++) {
        current_sum += arr[i];
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }

        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
    }

    return {max_sum, start, end};
}

// Function to handle the multiplier logic and adjust the array accordingly
int processArray(vector<int>& arr, int x) {
    // Case 1: x == 0, simply return the maximum sum subarray
    if (x == 0) {
        auto [max_sum, start, end] = kadane(arr);
        cout << "Maximum sum subarray is from index " << start << " to " << end << " with sum: " << max_sum << endl;
        return max_sum;
    }

    // Case 2: x > 0, find the max sum subarray and multiply it by x
    if (x > 0) {
        auto [max_sum, start, end] = kadane(arr);
        cout << "Multiplying elements from index " << start << " to " << end << " by " << x << endl;

        for (int i = start; i <= end; i++) {
            arr[i] *= x;
        }

        // Recalculate the maximum sum after modification
        auto [new_max_sum, _, __] = kadane(arr);
        cout << "After multiplication, new maximum sum subarray has sum: " << new_max_sum << endl;
        return new_max_sum;
    }

    // Case 3: x < 0, negate the array and find max subarray, then multiply original subarray by x
    if (x < 0) {
        vector<int> neg_arr = arr;

        // Negate all elements
        for (int& num : neg_arr) {
            num = -num;
        }

        auto [max_sum, start, end] = kadane(neg_arr);
        cout << "Multiplying original array's elements from index " << start << " to " << end << " by " << x << endl;

        // Multiply the original array's subarray by x
        for (int i = start; i <= end; i++) {
            arr[i] *= x;
        }

        // Recalculate the maximum sum in the modified original array
        auto [new_max_sum, _, __] = kadane(arr);
        cout << "After multiplication, new maximum sum subarray has sum: " << new_max_sum << endl;
        return new_max_sum;
    }

    return 0; // default return value
}

int main() {
    // vector<int> arr = {-3, 8, -2, 1, -6 };
    vector<int> arr = {1, 2, 4, -10 };
    // vector<int> arr = {3,2};
    int x;

    cout << "Enter multiplier x: ";
    cin >> x;

    int result = processArray(arr, x);
    cout << "Final maximum sum: " << result << endl;

    return 0;
}


