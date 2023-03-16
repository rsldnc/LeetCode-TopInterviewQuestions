/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h> 
 
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
	int **ret_arr = (int **)malloc(numRows * sizeof(int *));
	*returnColoumnSizes = (int *)malloc(numRows * sizeof(int));
	*returnSize = numRows;
	int i = 0;
	int size = 1;
	int j = 0;
	while (size <= numRows)
	{
		i = size - 1;
		ret_arr[i] = (int *)malloc(size * sizeof(int));
		if (size == 1)
			ret_arr[0][0] = 1;
		else
		{
			j = 0;
			while (j < size)
			{
				if (j == 0)
					ret_arr[i][j] = 1;
				else if (j == size - 1)
					ret_arr[i][j] = 1;
				else
					ret_arr[i][j] = ret_arr[i - 1][j - 1] + ret_arr[i - 1][j];
				j++;
			}
		}
		(*returnColumnSizes)[i] = size;
		size++;
	}
	return ret_arr;
}
