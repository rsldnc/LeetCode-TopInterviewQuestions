int climbStairs(int n)
{
	int i;
	int tab[45];
	
	tab[0] = 1;
	tab[1] = 2;
	i = 2;
	while (i < n)
	{
		tab[i] = tab[i-1] + tab[i-2];
		i++;
	}
	return tab[n-1];
}
