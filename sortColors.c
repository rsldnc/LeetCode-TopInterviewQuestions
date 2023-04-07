void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	len;
	int	swap;

	len = size - 1;
	while (len > 0)
	{
		i = 0;
		while (i < len)
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
		len--;
	}
}

void sortColors(int *nums, int numsSize)
{
	ft_sort_int_tab(nums, numsSize);
}
