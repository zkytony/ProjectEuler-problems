/*
  A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

  Find the largest palindrome made from the product of two 3-digit numbers.
  ------------------------------
  Formal definition of Palindromicity:
  Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. Consider a number n > 0 in base b ≥ 2, where it is written in standard notation with k+1 digits ai as:

  nn  n=sum_{i=0}^k(a_ib^i)

  with, as usual, 0 ≤ ai < b for all i and ak ≠ 0. Then n is palindromic if and only if ai = ak−i for all i. Zero is written 0 in any base and is also palindromic by definition. (k should be the number of digits)
*/

#include <iostream>
#include <vector>
#include <time.h> // clock_t

using namespace std;

vector<int> get_digits(int n)
{
  vector<int> result;
  int d = n % 10;
  n /= 10;
  result.push_back(d);
  while (n != 0)
    {
      d = n % 10;
      n /= 10;
      result.push_back(d);
    }
  return result;
}

// base = 10
bool is_palindrome(int n)
{
  vector<int> digits = get_digits(n);
  int size = digits.size();
  for (int i = 0; i < size / 2; i++)
    {
      if (digits.at(i) != digits.at(size-1-i))
        {
          return false;
        }
    }
  return true;
}

int my_method()
{
  int max = 0;
  for (int i = 999; i > 100; i--)
    {
      for (int j = 999; j > 100; j--)
        {
          if (i*j < max)
            {
              break;
            }
          if (is_palindrome(i*j))
            {
              if (i*j > max)
                {
                  max = i*j;
                }              
            }
        }
    } 
  return max;
}

/*
  Since P is palindromic:
  P=100000x10000y1000z100z10yx
  P=100001x10010y1100z
  P=119091x910y 100z

  Since 11 is prime, at least one of the two numbers has factor 11.
*/
int best_method()
{
  int max = 0;
  
  // use while loop since you can manipulate the condition more flexibly
  int a = 999;
  while (a >= 100)
    {
      int subtract = 0; // how much to subtract from b each time
      int b = 0;
      if (a % 11 == 0)
        {
          b = 999;
          subtract = 1;
        }
      else
        {
          b = 990; //The largest number less than or equal 999
          //and divisible by 11
          subtract = 11;
        }
      
      while (b >= 100)
        {
          if (a * b < max)
            {
              break; // it is not possible to get a larger palindrome now
            }
          if (is_palindrome(a * b) && max < a * b)
            {
              max = a * b;
            }
          b -= subtract; 
        }
      a -= 1;
    }
  return max;
}

int main()
{
  clock_t t;
  t = clock(); // start
  int max = best_method();
  t = clock() - t;
  cout << "Time taken by BEST method " << t << " clock cycle" << endl;
  cout << "RESULT: " << max << endl;

  t = clock();
  max = my_method();
  t = clock() - t;
  cout << "Time taken by My method " << t << " clock cycle" << endl;
  cout << "RESULT: " << max << endl;  

  // to get time in seconds,((float)t)/CLOCKS_PER_SEC
}
