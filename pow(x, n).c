double myPow(double x, int n)
{
	int i = n;
	int c_x = x;
	if (n == 0 || x == 1)
		return 1;
	else if (i < 0)
	{
		if (i == -2147483648)
			i++;
		i *= -1;
		x = 1 / x;
	}
	double result = 1;
	while (i > 0)
	{
		if (i % 2 == 1)
			result *= x;
		x *= x;
		i /= 2;
	}
	if (n == -2147483648)
		result /= c_x; 
	return result;
}
