#include <iostream>
#include <math.h>

using namespace std;

int sum_consecutive(int start, int end)
{
  return (start + end) * (end - start + 1) / 2;
}

// 1^2 + 2^2 + 3^2 + ... + 99^2 + 100^2 = 338 350 
// Squares are also the sum of odd numbers, so this is also equal to: 
// = 100*1 + 99*3 + 98*5 +...+ 2*197 + 1*199
// ALSO
// (1 + 2 + ... + n)^2 = n^2 * (n+1)^2 * 1/4 
// 1^2 + 2^2 + ... + n^2 = n * (n+1) * (2n+1) * 1/6 
// Thus easily applicable to any n.
int square_sum_consecutive(int start, int end)
{
  int sum = 0;
  for (int i = start; i <= end; i++)
    {
      sum += i * i;
    }
  return sum;
}

int main()
{
  long square_sum = pow(sum_consecutive(1, 100), 2);
  long sum_square = square_sum_consecutive(1, 100);
  cout << square_sum - sum_square << endl;
}
