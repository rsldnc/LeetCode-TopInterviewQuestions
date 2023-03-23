#include <math.h>

int isHappyHelper(int n)
{
	int c_n = n;
	int sum = 0;
	while (c_n)
	{
		sum += pow(c_n % 10, 2);
		c_n = c_n / 10;
	}
	if (sum == 1)
		return -1;
	else
		return sum;
}

bool isHappy(int n)
{
	int c_n = n;
	char tab[810] = {'u'};
	while (isHappyHelper(c_n) != -1)
	{
		c_n = isHappyHelper(c_n);
		if (tab[c_n] == 'a')
			return false;
		else
			tab[c_n] = 'a';
	}
	return true;
}
