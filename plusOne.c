/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
 
int ft_valid(int *digits, int digitsSize)
{
	int i = 0;
	while (i < digitsSize)
	{
		if (digits[i] != 9)
			return 0;
		i++;
	}
	return 1;
}
 
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int i;
	
	i = 0;
	int *ret_arr;
	if (ft_valid(digits, digitsSize))
	{
		ret_arr = (int *)malloc((digitsSize + 1) * sizeof(int));
		*returnSize = digitsSize + 1;
		ret_arr[i] = 1;
		i++;
		while (i < digitsSize + 1)
		{
			ret_arr[i] = 0;
			i++;
		}
	}
	else
	{
		ret_arr = (int *)malloc((digitsSize) * sizeof(int));
		*returnSize = digitsSize;
		while (i < digitsSize)
		{
			ret_arr[i] = digits[i];
			i++;
		}
		i--;
		if (ret_arr[i] == 9)
		{
			while (ret_arr[i] == 9)
			{	
				ret_arr[i] = 0;	
				i--;
			}
			ret_arr[i] = ret_arr[i] + 1;
		}
		else
			ret_arr[i] = ret_arr[i] + 1;
	}
	return ret_arr;
}
