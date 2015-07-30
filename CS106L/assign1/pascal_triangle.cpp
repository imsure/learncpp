/**
 * A short and concise description goes here.
 * *************************************************
 *
 * Author: Shuo Yang
 * Email: imsure95@gmail.com
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/**
 * The mathematical combinations.
 */
int combinations(int n, int k)
{
  if (n == k) return 1;
  if (k == 0) return 1;

  return combinations(n-1, k-1) + combinations(n-1, k);
}

int get_num_digit(int value)
{
  if (value < 10) return 1;
  else return 1 + get_num_digit(value/10);
}

void pascal_triangle(int depth)
{
  int left_adjust;
  int num_digit;
  int value;
  
  for (int n = 0; n < depth; ++n) {
    left_adjust = (depth - n) * 2;
    for (int k = 0; k <= n; ++k) {
      value = combinations(n, k);
      if (k == 0) {
	cout << setw(left_adjust) << value;
      } else {
	num_digit = get_num_digit(value);
	cout << setw(num_digit+3) << value;
      }
    }
    cout << endl;
  }
}

/**
 * The main program.
 */
int main( int argc, char *argv[] )
{
  // for (int n = 0; n <= 7; ++n) {
  //   for (int k = 0; k <= n; ++k) {
  //     cout << "c(" << n << "," << k << ") = " << combinations(n, k) << endl;
  //   }
  // }

  pascal_triangle(10);
  return 0;
}

