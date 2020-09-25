#include <bitset>
#include <cassert>
#include <iostream>

bool is_odd_binaryhack(int number) {
  bool result = false;

  result = number & 1;

  return result;
}

bool const ODD = true;
bool const EVEN = false;

void test_is_odd_binaryhack() {
  int a{5};
  int b{4};

  assert(is_odd_binaryhack(a) == ODD);
  assert(is_odd_binaryhack(b) == EVEN);
}

bool has_same_sign(int first, int second) {
  bool result{false};

  result = (first ^ second) > 0;

  return result;
}

void test_has_same_sign() {
  int a{-42};
  int b{42};
  int c = 0;
  assert(has_same_sign(a, b) == false);
  assert(has_same_sign(c, b) == true);
}

const int THREE{3};
const int ONE{1};
const int TWO{2};
const int FIVE{5};
const int FOUR{4};
const int ZERO{0};

void test_binary_increment() {
  // -x = ~x + 1;
  // => -~x = ~~x + 1 <=> -~x = x + 1;

  assert(FOUR + ONE == -~FOUR);
  assert(FIVE == -~FOUR);

  assert(TWO + ONE == -~TWO);
  assert(THREE == -~TWO);

  assert(ZERO + ONE == -~ZERO);
  assert(ONE == -~ZERO);
}

void test_binary_swap() {
  int a = FIVE;
  int b = ONE;

  if (a != b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
  }

  assert(a == ONE);
  assert(b == FIVE);
}

int invert_bit(int number, char bit_1_based_index) {
  int result{0};
  int mask{1 << (bit_1_based_index - 1)};
  result = number ^ mask;
  return result;

  /*
   * result = number & ~mask; // turn off bit
   * result = number | mask;  // turn on bit
   * result = number & mask;  // check if the bit is set to 1
   */
}

int turn_off_bit(int number, char bit_1_based_index) {
  return number & ~(1 << (bit_1_based_index - 1));
}
int turn_on_bit(int number, char bit_1_based_index) {
  return number | (1 << (bit_1_based_index - 1));
}
int check_bit(int number, char bit_1_based_index) {
  return number & (1 << (bit_1_based_index - 1));
}

void test_invert_check_turn_on_off_bit() {
  int a{0b0101010};  // 42
  int b{0b0100010};  // 34

  int inv_a = invert_bit(a, FOUR);
  int inv_b = invert_bit(b, FOUR);

  assert(inv_a == b);
  assert(a == inv_b);

  assert(turn_off_bit(a, FOUR) == b);
  assert(turn_on_bit(b, FOUR) == a);
  assert(check_bit(a, FOUR) > 0);
  assert(check_bit(b, FOUR) == 0);
};

// The expression (n & (n – 1)) will turn off the rightmost set bit of given
// number.

/*
00010100   &                 (n = 20)
00010011                     (n-1 = 19)
~~~~~~~~
00010000
*/

// Check if given positive integer is a power of 2 without using any branching
// or loop.

bool is_power_of_2(unsigned n) {
  std::cout << n << " in binary is " << std::bitset<8>(n) << "\n";
  std::cout << n - 1 << " in binary is " << std::bitset<8>(n - 1) << "\n\n";

  return !(n & (n - 1));
}

void test_if_n_is_a_power_of_2() {
  unsigned n = 16;

  if (is_power_of_2(n))
    std::cout << n << " is power of two";
  else
    std::cout << n << " is not a power of two";
};

// Find position of the rightmost set bit
/*
 * The idea is to unset the rightmost bit of number n and XOR the result with n.
 * Then the position of the rightmost set bit in n will be the position of the
 * only set bit in the result. Note that if n is odd, we can directly return 1
 * as first bit is always set for odd numbers.
 */

int rightmost_set_bit_position(uint n) {
  // if number is odd, return 1
  if (n & 1) return 1;

  // unset rightmost bit and xor with number itself
  n = n ^ (n & (n - 1));

  // find the position of the only set bit in the result
  // we can directly return log2(n) + 1 from the function
  int pos = 0;
  while (n) {
    n = n >> 1;
    pos++;
  }
  return pos;
}

void test_find_rightmost_set_bit_position() {
  uint n = 20;

  std::cout << n << " in binary is " << std::bitset<8>(n) << std::endl;
  std::cout << "Position of the rightmost set bit is "
            << rightmost_set_bit_position(n);
};

using test = void (*)(void);

int main() {
  using namespace std;

  test tests[]{
      test_is_odd_binaryhack,
      test_has_same_sign,  // TODO: use bitset for showing bit representation of
                           // int
      test_binary_increment,
      test_binary_swap,
      test_invert_check_turn_on_off_bit,

      test_if_n_is_a_power_of_2,
      test_find_rightmost_set_bit_position,
  };
  uint counter{0};
  for (test t : tests) {
    cout << endl;
    cout << "=> Running test " << counter++;
    cout << endl;
    t();
  }

  cout << endl;
  cout << "==> All asserts were passed! <==" << endl;
  cout << endl;
  return 0;
}
