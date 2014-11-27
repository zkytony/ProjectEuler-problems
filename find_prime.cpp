/*
  By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

  What is the 10 001st prime number?
*/

#include <iostream>
#include <math.h> // sqrt
#include <time.h> // clock

using namespace std;

/**
   A simple but less efficient function

   1. Loop from 2 to sqrt(n)
   2. skip all numbers that are even, and numbers that are not multiples of 
      6+-1
 */
bool isPrime(long n)
{
  if (n < 2) return false;
  if (n < 4) return true;
  if (n % 2 == 0) return false;
  if (n % 6 != 1 && n % 6 != 5) return false;
  
  for (int i = 2; i <= sqrt(n); i++)
    {
      if (n % i == 0) return false;
    }
  return true;
}

int main()
{
  clock_t t;
  t = clock(); // start

  long now = 0;
  int count = 1;

  long num = 1;
  while (count <= 10001)
    {
      if (isPrime(num))
        {
          now = num;
          count++;
        }
      num++;
    }
  cout << "10001th : " << now << endl;

  t = clock() - t;
  cout << "TIME TAKEN: " << t << " clock cycle." << endl;
}
