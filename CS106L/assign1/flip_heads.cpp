/**
 * Simulate coin tosses. Stop when 3 consecutive tosses were made.
 * ***************************************************************
 *
 * Author: Shuo Yang
 * Email: imsure95@gmail.com
 */

#include <iostream>
#include <cstdlib> // rand, srand
#include <time.h>

using namespace std;

const int HEAD = 1;
const int TAIL = 0;
const int CONSECUTIVE_HEAD_COUNT = 3;

/**
 * The main program.
 */
int main( int argc, char *argv[] )
{
  int head_count = 0;
  int current_toss;
  time_t seconds;
  
  time(&seconds); // get time of the day in seconds
  srand((unsigned)seconds); // set the seed for pseudo-random number

  while (head_count < 3) {
    current_toss = rand() % 2;
    if (current_toss == HEAD) {
      cout << "head" << endl;
      head_count++;
    } else {
      cout << "tail" << endl;
      head_count = 0; // reset
    }
  }

  cout << "Three consecutive heads tossed!" << endl;
  
  return 0;
}

