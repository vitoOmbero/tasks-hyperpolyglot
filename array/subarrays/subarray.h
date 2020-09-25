#ifndef SUBARRAY_H
#define SUBARRAY_H
#include <limits>

struct Subarray {
  const int *start;
  const int *end;

  bool operator==(const Subarray &rhs) const {
    return this->start == rhs.start && this->end == rhs.end;
  }

  int get_length() {
    int *start_ = const_cast<int *>(start);
    int *end_ = const_cast<int *>(end);
    return unsec_count_wo_sizeof(start_, end_);
  }

private:
  int unsec_count_wo_sizeof(int *ptr_left, int *ptr_right) {
    int l{0};
    while ((ptr_left != ptr_right) && (l <= std::numeric_limits<int>::max())) {
      ptr_right--;
      l++;
    }
    return l;
  }
};
#endif // SUBARRAY_H
