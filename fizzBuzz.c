/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int i;
	int cnbr = nbr;
	char *a;
	int j;

	i = 0;
	while (nbr)
	{
		i++;
		nbr = nbr / 10;
	}
	a = (char *)malloc(i * sizeof(char) + 1);
	j = i - 1;
	while (cnbr)
	{
		a[j] = (cnbr % 10) + '0';
		j--;
		cnbr = cnbr / 10;
	}
	a[i] = '\0';
	return (a);
}
 
char **fizzBuzz(int n, int *returnSize)
{	
	int i = 1;
	char **ret_arr = (char **)malloc(n * sizeof(char *));
	*returnSize = n;
	int j = 0;
	while (i <= n)
	{
		j = i - 1;
		if ((i % 3 == 0) && (i % 5 == 0))
		{
			ret_arr[j] = (char *)malloc(8 * sizeof(char));
			ret_arr[j] = "FizzBuzz";
		}
		else if (i % 5 == 0)
		{
			ret_arr[j] = (char *)malloc(4 * sizeof(char));
			ret_arr[j] = "Buzz";
		}
		else if (i % 3 == 0)
		{
			ret_arr[j] = (char *)malloc(4 * sizeof(char));
			ret_arr[j] = "Fizz";
		}
		else
		{
			ret_arr[j] = ft_itoa(i);
		}
		i++;
	}
	return ret_arr;
}
