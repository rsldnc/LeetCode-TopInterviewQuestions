int mySqrt(int x)
{
	int i;

	if (x == 0)
		return 0;
	i = 1;
	while (i <= x / i)
	{
		i++;
	}
	return (i - 1);
}
