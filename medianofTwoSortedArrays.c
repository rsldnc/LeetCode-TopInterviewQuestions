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

#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int size = nums1Size + nums2Size;
	int i = 0;
	double med;
	int *tab = (int *)malloc(size * sizeof(int));
	while (i < nums1Size)
	{
		tab[i] = nums1[i];
		i++;
	}
	while (i < size)
	{
		tab[i] = nums2[i - nums1Size];
		i++;
	}
	ft_sort_int_tab(tab, size);
	i = size / 2;
	if (size % 2 == 0)
	{
		double num1 = tab[i - 1];
		double num2 = tab[i];
		med = (num1 + num2) / 2;
	}
	else
		med = tab[i];
	free(tab);
	return med;
}
