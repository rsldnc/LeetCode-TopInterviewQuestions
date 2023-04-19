void replace_notprime(int *tab, int n)
{
	int	i;

	i = 2;
	while (i * i < n)
	{
		if (tab[i])
		{
			int j = i * i;
			while (j < n)
			{
				tab[j] = 0;
				j += i;
			}
		}
		i++;
	}
}

int countPrimes(int n)
{
	if (n < 2)
		return 0;
	int tab[n];
	memset(tab, 1, n * sizeof(int));
	replace_notprime(tab, n);
	
	int i = 2;
	int count = 0;
	while (i < n)
	{
		if (tab[i])
			count++;
		i++;
	}
	return count;
}
