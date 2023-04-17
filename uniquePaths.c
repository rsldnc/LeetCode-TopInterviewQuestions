int uniquePaths(int m, int n)
{
	int area[m][n];
	int i = 0;
	while (i < m)
	{
		area[i][0] = 1;
		i++;
	}
	int j = 0;
	while (j < n)
	{
		area[0][j] = 1;
		j++;
	}
	i = 1;
	while (i < m)
	{
		j = 1;
		while (j < n)
		{
			area[i][j] = area[i-1][j] + area[i][j-1];
			j++;
		}
		i++;
	}
	return area[m - 1][j - 1];
}
