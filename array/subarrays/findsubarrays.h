#ifndef FINDSUBARRAYS_H
#define FINDSUBARRAYS_H
#include <array>
#include <unordered_map>
#include <vector>

#include "subarray.h"

// Function to find sub-arrays with given sum in an array // O(n^2)
template <typename T, std::size_t const N>
std::vector<Subarray> *find_subarrays_NAIVE(std::array<T, N> &arr, int sum) {
  std::vector<Subarray> *result = new std::vector<Subarray>();

  for (int i = 0; i < N; i++) {
    int sum_so_far = 0;

    // consider all sub-arrays starting from i and ending at j
    for (int j = i; j < N; j++) {
      // sum of elements so far
      sum_so_far += arr[j];

      // if sum so far is equal to the given sum
      if (sum_so_far == sum) {
        result->push_back(Subarray{&arr[i], &arr[j]});
      }
    }
  }

  return result;
}

template <typename T, std::size_t const N>
// Function to find subarrays with given sum in an array //O(n) amortized
std::vector<Subarray> *find_subarrays_OPT(std::array<T, N> &arr, int sum) {
  // create an empty map of vectors for storing end index of all
  // subarrays with sum of elements so far
  std::unordered_map<int, std::vector<int>> subarrs_map;

  // To handle the case when the subarray with given sum starts
  // from 0th index
  subarrs_map[0].push_back(-1);

  int sum_so_far = 0;

  // traverse the given array
  for (int index = 0; index < N; index++) {
    // sum of elements so far
    sum_so_far += arr[index];

    // check if there exists at-least one sub-array with given sum
    auto itr = subarrs_map.find(sum_so_far - sum);
    if (itr != subarrs_map.end()) {
      // print all sub-arrays with given sum
      to_subarray(arr, index,
                  map[itr->first]); // make Subarray in to_Subarray function and
                                    // put into result
    }

    // insert (sum so far, current index) pair into the map of vectors
    subarrs_map[sum_so_far].push_back(index);
  }
}

#endif // FINDSUBARRAYS_H
