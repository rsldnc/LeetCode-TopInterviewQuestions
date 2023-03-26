#include <math.h>

bool isPowerOfThree(int n)
{
	if (n < 3 && n != 1)
		return false;
	int c_n = n;
	int exp = 0;
	while (c_n % 3 == 0)
	{
		exp++;
		c_n = c_n / 3;
	}
	if (pow(3, exp) == n)
		return true;
	else
		return false;
}
