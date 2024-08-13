void	ft_sort(int *tab, int size)
{
	int	len = size - 1;
	while (len > 0)
	{
		int i = 0;
		while (i < len)
		{
			if (tab[i] < tab[i + 1])
			{
				int swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
		len--;
	}
}

int hIndex(int* citations, int citationsSize)
{
    ft_sort(citations, citationsSize);
    int i = 0;
    while (i < citationsSize)
    {
        if(citations[i] >= i + 1)
            i++;
        else
            break;   
    }
    return i;
}
