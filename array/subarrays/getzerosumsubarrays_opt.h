#ifndef GETZEROSUMSUBARRAYS_OPT_H
#define GETZEROSUMSUBARRAYS_OPT_H
#include <list>
#include <unordered_map>

#include "subarray.h"

// Function to print all sub-arrays with 0 sum present
// in the given array
std::list<Subarray> *getZeroSumSubarrays_OPT(int arr[], int n) {
  using namespace std;

  list<Subarray> *subarrs = new list<Subarray>();

  // create an empty multi-map to store ending index of all
  // sub-arrays having same sum
  unordered_multimap<int, int> map;

  // insert (0, -1) pair into the map to handle the case when
  // sub-array with 0 sum starts from index 0
  map.insert(pair<int, int>(0, -1));

  int sum = 0;

  // traverse the given array
  for (int i = 0; i < n; i++) {
    // sum of elements so far
    sum += arr[i];

    // if sum is seen before, there exists at-least one
    // sub-array with 0 sum
    if (map.find(sum) != map.end()) {
      auto it = map.find(sum);

      // find all sub-arrays with same sum
      while (it != map.end() && it->first == sum) {
        // Subarray from [i to j]";
        subarrs->push_back(Subarray{&arr[it->second + 1], &arr[i]});
        it++;
      }
    }

    // insert (sum so far, current index) pair into multi-map
    map.insert(pair<int, int>(sum, i));
  }

  return subarrs;
}
#endif // GETZEROSUMSUBARRAYS_OPT_H
