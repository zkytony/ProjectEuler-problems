/*
  The prime factors of 13195 are 5, 7, 13 and 29.

  What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <stdlib.h>     /* abs  */
#include <math.h>       /* log2, pow, sqrt */
#include <cmath>        /* floor */

using namespace std;

/**
  Eclid's Algorithm:
  for (n1, n2) produce a new pair of number consists of the smaller one of n1 and n2, and their difference; Keep doing this utill the numbers in the pair is the same
*/
int gcd(int n1, int n2)
{
  if (n1 != n2)
    {
      int smaller = n1 < n2 ? n1 : n2;
      int diff = abs(n2 - n1);
      return gcd(smaller, diff); // keep doing
    }
  else
    {
      return n1;
    }
}

/**
   Two numbers are coprime if and only if the GCD is 1
 */
bool isCoprime(int n1, int n2)
{
  return gcd(n1, n2) == 1; // if GCD = 1, then two numbers are coprime
}

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
  
  for (int i = 2; i < sqrt(n); i++)
    {
      if (n % i == 0) return false;
    }
  return true;
}

/**
   Return the largest factor of the input integer n
 */
int largestFactor(long n)
{
  double root = sqrt(n);
  // wish to start from sqrt(n)
  int start = (int)root;
  for (int i = start; i > 2; i--)
    {
      if (n % i == 0) return i;
    }
  return 1;
}

/**
   Return the largest prime factor of input integer n
 */
int largestPrimeFactor(long n)
{
  double root = sqrt(n);
  // wish to start from sqrt(n)
  int start = (int)root;
  for (int i = start; i > 2; i--)
    {
      if (n % i == 0 && isPrime(i)) return i;
    }
  return 1;
}

/**
  AKS primality test is based on the following theorem: An integer n (>=2) is prime if and only if the polynomial congruence relation
    
  (x-a)^n ≡ (x^n-a)(mod p)

  holds for all integers 'a' that is coprime to n. Notice that x here is a free variable; x is never substituted by a number; instead you would have to expand (x-a)^n and compare the coefficients of the x powers

  Procedure:
  input n > 1
  1. if n = a^b for a > 1 and b > 1, output composite.
      For (b = 2, b < log_2(n), b++) ...
  2. Find the smallest r such that O_r(n) > (log n)^2
  3. If 1 < (a, n) < n for some a <= r, output composite
  4. If n <= r, output PRIME
  5. For a = 1 to sqrt(phi(r))*log(n) do
     if ((x+a)^n != x^n + a (mod x^r - 1,n)), output composite
  6. Output PRIME

  Here O_r(n) is the multiplicative order of n modulo r, log is the binary logarithm, and phi(r) is Euler's totient function of r.
  
  Some Prerequisite Knowledge:
  1. Mod: For a positive integer n, two integers a and b are said to be congruent modulo n, and written as

  a ≡ b (mod n)

  if their difference a − b is an integer multiple of n (or n divides a − b).
  (a-b) % n == 0

  2. Multiplicative order: In number theory, given an integer 'a' and a positive integer n with gcd(a,n) = 1, the multiplicative order of a modulo n is the smallest positive integer k with

  a^k ≡ 1 (mod n).

  The order of a modulo n is usually written ord_n(a), or O_n(a).
  
  The following code is implemented based on the pseudocode at https://primes.utm.edu/prove/prove4_3.html
*//*
bool isPrime_AKS(int n)
{
  if (n < 2) return false;
  if (n < 4) return true;
  if (n % 2 == 0) return false;

  // 1.If n = a^b for integers a > 1 and b > 1, output composite. 
  for (int b = 2; b < log2(n); b++)
    {
      double a = pow(n, 1.0/b);
      if (a % 1 == 0) return false;
    }

  // 2.Find the smallest r such that O_r(n) > (log n)^2
  int r = 2;
  while (r < n)
    {
      if (gcd(n,r) != 1) return false;
      if (isPrime(r) && r > 2)
        {
          int q = largestFactor(r-1);
          if ((q > 4*sqrt(r)*log2(n)) && ((pow(n, (r-1.0)/q)-1) % r != 0))
            {
              break;
            }
        }
      r++;
    }
  /* Stopped here because implementing polynomial multiplication is complicated
  for (a = 1; a < 2*sqrt(r)*log2(n))
    {
      if (
    }
  return false;
}*/

int main()
{
  long n = 600851475143;
  cout << "Largest Prime Factor: " << largestPrimeFactor(n) << endl;
}
