#ifndef REVERSE_CONSECUTIVE_SUBARRAY_H
#define REVERSE_CONSECUTIVE_SUBARRAY_H
#include <array>

#include "subarray.h"

template <std::size_t const N>
void swap(std::array<int, N> &array, int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

template <std::size_t const N>
void reverse_subarray(std::array<int, N> &array, int i, int j) {
  while (i < j) {
    swap(array, i, j);
    i++, j--;
  }
}

template <std::size_t const N>
std::array<int, N> reverse_each_subgroup(std::array<int, N> array,
                                         int start_index, int end_index,
                                         int subgroup_length) {
  // return if sub-array length is less than m
  if (subgroup_length > end_index - start_index + 1) {
    return array;
  }

  // reverse every consecutive m elements
  for (int i = start_index; i <= end_index; i = i + subgroup_length) {
    // check if subarray length is atleast m
    if (i + subgroup_length - 1 <= end_index) {
      reverse_subarray(array, i, i + subgroup_length - 1);
    }
  }

  return array;
}

#endif // REVERSE_CONSECUTIVE_SUBARRAY_H
