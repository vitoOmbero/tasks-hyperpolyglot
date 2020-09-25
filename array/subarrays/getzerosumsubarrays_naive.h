#ifndef GETZEROSUMSUBARRAYS_H
#define GETZEROSUMSUBARRAYS_H

#include <list>
#include <unordered_map>

#include "subarray.h"

// Function to print all sub-arrays with 0 sum present
// in the given array
std::list<Subarray> *getZeroSumSubarrays_NAIVE(int const arr[], int n) {
  using namespace std;

  list<Subarray> *subarrs = new list<Subarray>();

  // consider all sub-arrays starting from i
  for (int i = 0; i < n; i++) {
    int sum = 0;

    // consider all sub-arrays ending at j
    for (int j = i; j < n; j++) {
      // sum of elements so far
      sum += arr[j];

      // if sum is seen before, we have found a sub-array
      // with 0 sum
      if (sum == 0) {
        // Subarray from [i to j]";
        subarrs->push_back(Subarray{&arr[i], &arr[j]});
      }
    }
  }

  return subarrs;
}
#endif // GETZEROSUMSUBARRAYS_H
