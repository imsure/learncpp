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

// 
const int LEFT_MOST_INTERVAL = 2;
const int RIGHT_MOST_INTERVAL = 2;
const int UNIT_DISTANCE_LAST_ROW = 4;

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

static void print_row(int row_num, int left_most_adjustment, int right_most_adjustment)
{
  vector<int> values;
  int v, num_digit;
  int row_len = 0;

  if (row_num == 0) {
    cout << setw(left_most_adjustment) << 1 << endl;
    return;
  }

  if (left_most_adjustment == 0) { // last row
    v = combinations(row_num, 0);
    values.push_back(v);
    row_len += 1;
    
    for (int k = 1; k <= row_num; ++k) {
      v = combinations(row_num, k);
      values.push_back(v);
      num_digit = get_num_digit(v);
      row_len += 4; // 4 whitespace intervals for the last row
    }
    print_row(row_num-1, left_most_adjustment+3, row_len-2);
    cout << setw(left_most_adjustment) << 1;
    for (int i = 1; i < values.size()-1; ++i) {
      cout << setw(4) << values[i];
    }
    cout << setw(row_len - 4*(values.size()-2) - 1) << 1 << endl;
  } else {
    print_row(row_num-1, left_most_adjustment+2, right_most_adjustment-2);
    cout << setw(left_most_adjustment) << 1;
    // distance between first and last element.
    int distance = right_most_adjustment - left_most_adjustment - 1;
    int unit_distance = distance / row_num;
    int left_over = distance % row_num;
    for (int i = 1; i < row_num; ++i) {
      if (left_over > 0) {
	cout << setw(unit_distance+1) << combinations(row_num, i);
	left_over--;
      } else {
	cout << setw(unit_distance) << combinations(row_num, i);
      }
    }
    cout << setw(right_most_adjustment-left_most_adjustment-distance+unit_distance) << 1 << endl;
  }
}

void print_pascal_triangle(int depth)
{
  print_row(depth-1, 0, 0);
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

  print_pascal_triangle(10);
  return 0;
}

