#ifndef CONSECUTIVE_INTEGERS_H
#define CONSECUTIVE_INTEGERS_H
#include <vector>

#include "subarray.h"

// Function to check if sub-array arr[i..j] is formed by consecutive
// integers. Here min and max denotes the minimum and maximum element
// in the sub-array respectively
bool isConsecutive(int arr[], int i, int j, int min, int max)
{
    // The difference between maximum and minimum element in it should be
    // exactly equal to length of the subarray minus one

    // in order for an array to contain consecutive integers, the diff
    // between maximum and element element in it should be exactly j-i
    if (max - min != j - i)
        return false;

    // create a visited array (we can also use a set)
    std::vector<bool> visited(j - i + 1);

    // traverse the sub-array and checks if each element appears only once
    for (int k = i; k <= j; k++)
    {
        // if element is seen before, return false
        if (visited[arr[k] - min])
            return false;

        // mark element as seen
        visited[arr[k] - min] = true;
    }

    // we reach here when all elements in array are distinct
    return true;
}


// Find largest sub-array formed by consecutive integers
Subarray find_max_subarr_consecutive_integers(int arr[], int n)
{
    int len = 1;
    int start = 0, end = 0;

    // consider each sub-array formed by A[i..j]

    // i denotes the beginning of sub-array
    for (int i = 0; i < n - 1; i++)
    {
        // stores minimum and maximum element in an sub-array A[i..j]
        int min_val = arr[i], max_val = arr[i];

        // j denotes the end of sub-array
        for (int j = i + 1; j < n; j++)
        {
            // update minimum and maximum element of the sub-array
            min_val = std::min(min_val, arr[j]);
            max_val = std::max(max_val, arr[j]);

            // check if subarray A[i..j] is formed by consecutive integers
            if (isConsecutive(arr, i, j, min_val, max_val))
            {
                if (len < max_val - min_val + 1) {
                    len = max_val - min_val + 1;
                    start = i;
                    end = j;
                }
            }
        }
    }

    // print maximum length sub-array
    // cout << "The largest sub-array is [" << start << ", " << end << "]";

    return Subarray{&arr[start], &arr[end]};
}
#endif // CONSECUTIVE_INTEGERS_H
