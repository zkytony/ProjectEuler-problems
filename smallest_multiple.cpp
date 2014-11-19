/*
  2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

  What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
  ------------------------------
  Fundamental theorem of arithmetic:

  Every integer greater than 1 either is prime itself or is the product of prime numbers
  ------------------------------
  Best solution:
  This does not require programming at all. Compute the prime factorization of each number from 1 to 20, and multiply the greatest power of each prime together:
  20 = 2^2 * 5 
  19 = 19 
  18 = 2 * 3^2 
  17 = 17 
  16 = 2^4 
  15 = 3 * 5 
  14 = 2 * 7 
  13 = 13 
  11 = 11 
  
  All others are included in the previous numbers. 
  ANSWER: 2^4 * 3^2 * 5 * 7 * 11 * 13 * 17 * 19 = 232 792 560

  My solution is dumb
 */

#include <iostream>
#include <time.h> // clock_t

using namespace std;

// see if n can divide all number from 0 to lim
bool can_divide_all(int n, int lim)
{
  for (int i = lim; i > (lim/2); i--)
    {
      int factor = i * (i-1);
      if (n % factor != 0)
        {
          return false;
        }
    }
  return true;
}

int main()
{
  clock_t t;
  t = clock(); // start

  int n = 2520;
  while (!can_divide_all(n, 20)) {
    n++;
  }
  cout << "Smallest multiple is " << n << endl;

  t = clock() - t;
  cout << "TIME TAKEN: " << t << " clock cycle." << endl;
}
