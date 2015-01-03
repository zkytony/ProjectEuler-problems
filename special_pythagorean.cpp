/*
  A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
  a2 + b2 = c2

  For example, 32 + 42 = 9 + 16 = 25 = 52.

  There exists exactly one Pythagorean triplet for which a + b + c = 1000.
  Find the product abc.

  ==============================
  My thoughts:

  By algebra, a, b, c will have this relationship:
  (a+b) - ab/1000 = 500, where c is replaced by c = 1000 - (a+b)
  This implies that both ab is a product of 1000, also, a + b is less than 500
*/

#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
  clock_t t;
  t = clock(); // start clock

  for (int a = 500; a >= 1; a--) 
    {
      for (int b = 500; b >= 1; b--) 
        {
          if ((a < b) && (b < (1000-a-b) && (a+b - a*b/(double)1000) == 500))
            {
              printf("a = %d\nb = %d\nc = %d\n", a, b, 1000-(a+b));
              goto endloop;
            }
        }
    }

 endloop:
  printf("END\n");

  t = clock() - t;
  cout << "TIME TAKEN: " << t << " clock cycle." << endl;
}
