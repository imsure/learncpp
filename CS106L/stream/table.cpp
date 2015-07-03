/**
 * Reads in data in table-data.txt and writes out as a table.
 * **********************************************************
 *
 * Author: Shuo Yang
 * Email: imsure95@gmail.com
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_LINES = 4;
const int NUM_COLS = 3;
const int COL_WIDTH = 20;

void print_table_head()
{
  for (int column = 1; column < NUM_COLS; ++column) {
    cout << setfill('-') << setw(COL_WIDTH) << "" << "-+-";
  }

  cout << setfill('-') << setw(COL_WIDTH) << "" << setfill(' ') << endl;
}

void print_table_body()
{
  ifstream input("table-data.txt");
  if (!input.is_open()) {
    cerr << "Cannot open the input file!" << endl;
    exit(-1);
  }

  for (int k = 1; k <= NUM_LINES; ++k) {
    int int_val;
    double double_val;

    input >> int_val >> double_val;
    cout << setw(COL_WIDTH) << k << " | ";
    cout << setw(COL_WIDTH) << int_val << " | ";
    cout << setw(COL_WIDTH) << double_val << endl;
  }
}

/**
 * The main program.
 */
int main( int argc, char *argv[] )
{
  print_table_head();
  print_table_body();
  return 0;
}

