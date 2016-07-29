/**
 * Print out a pascal triangle beautifully.
 * *************************************************
 *
 * Author: Shuo Yang
 * Email: imsure95@gmail.com
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int MIN_UNIT_DISTANCE_LAST_ROW = 4;

int space_adjustment;

/**
 * Calculate the mathematical combinations c(n,k).
 */
int combinations(int n, int k)
{
  if (n == k) return 1;
  if (k == 0) return 1;

  return combinations(n-1, k-1) + combinations(n-1, k);
}

/**
 * Get the number of digits in 'value'.
 */
int get_num_digit(int value)
{
  if (value < 10) return 1;
  else return 1 + get_num_digit(value/10);
}

/**
 * Calculate the distance between two adjacent elements
 * of the last row.
 */
static int unit_distance_last_row(int row_num)
{
  int mid_element_index = row_num / 2 + row_num % 2;
  int value = combinations(row_num, mid_element_index);
  int num_digit = get_num_digit(value);
  return num_digit >= MIN_UNIT_DISTANCE_LAST_ROW? num_digit+1 : MIN_UNIT_DISTANCE_LAST_ROW;
}

/**
 * Adjust the length of the last row such that we can place
 * the border (all 1s) evenly.
 *
 *      1
 *    1   1
 * 1 ....... 1
 */
static int adjust_last_row_len(int last_row_len, int num_rows)
{
  int num_ones = 0;

  num_ones = (num_rows-1)*2 + 1;

  int total_space = last_row_len - num_ones; // total whitespaces can be divided.
  while (total_space % (2*(num_rows-1))) {
    last_row_len++;
    total_space = last_row_len - num_ones; // total whitespaces can be divided.
  }

  return last_row_len;
}

/** 
 * Recursively print out each row of a pascal triangle.
 */
static void print_row(int row_num, int left_most_adjustment, int right_most_adjustment)
{
  vector<int> values;
  int v, num_digit;

  if (row_num == 0) { // Base case
    cout << setw(left_most_adjustment) << 1 << endl;
    return;
  }

  if (left_most_adjustment == 0) { // Processing the last row.
    int row_len = 0;
    v = combinations(row_num, 0);
    values.push_back(v);
    row_len += 1;

    // Get the unit distance between two adjacent elements.
    int unit_distance = unit_distance_last_row(row_num);
    
    for (int k = 1; k <= row_num; ++k) {
      v = combinations(row_num, k);
      values.push_back(v);
      row_len += unit_distance;
    }

    // Adjust the length of last row.
    row_len = adjust_last_row_len(row_len, row_num+1);
    int num_ones = row_num*2 + 1;
    space_adjustment = (row_len-num_ones) / (2*(row_num));
    space_adjustment++;

    // Debug:
    cout << "unit distance between elements of last row= " << unit_distance << endl;
    cout << "# rows: " << row_num+1 << ", last row length: " << row_len << endl;
    cout << "space adjustment between two outmost 1s: " << space_adjustment << endl;

    print_row(row_num-1, left_most_adjustment+space_adjustment+1, row_len-space_adjustment);
    cout << setw(left_most_adjustment) << 1;
    unit_distance = (row_len-1) / row_num; // re-adjust
    for (int i = 1; i < values.size()-1; ++i) {
      cout << setw(unit_distance) << values[i];
    }
    cout << setw(row_len - unit_distance*(values.size()-2) - 1) << 1 << endl;
  } else { // Processing rows above the last row.
    print_row(row_num-1, left_most_adjustment+space_adjustment, right_most_adjustment-space_adjustment);
    cout << setw(left_most_adjustment) << 1;
    // Distance between first and last element.
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
  print_pascal_triangle(20);
  return 0;
}

