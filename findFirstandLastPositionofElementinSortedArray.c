/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h> 
 
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	*returnSize = 2;
	int *ret_arr = (int *)malloc(2 * sizeof(int));
	ret_arr[0] = -1;
	ret_arr[1] = -1;
	int i = 0;
	while (i < numsSize)
	{
		if (nums[i] == target)
		{
			ret_arr[0] = i;
			while (i + 1 < numsSize && nums[i + 1] == target)
				i++;
			ret_arr[1] = i;
			return ret_arr;
		}
		i++;
	}
	return ret_arr;
}
