/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h> 
 
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
	int i = 0;
	int index1[1001] = {0};
	int index2[1001] = {0};
	while (i < nums1Size)
	{
		index1[nums1[i]] += 1;
		i++;
	}
	i = 0;
	while (i < nums2Size)
	{
		index2[nums2[i]] += 1;
		i++;
	}
	i = 0;
	int *tab = (int *)malloc(nums2Size * sizeof(int));
	int j = 0;
	while (i < nums2Size)
	{
		if (index2[nums2[i]] > 0 && index1[nums2[i]] > 0)
		{
			tab[j] = nums2[i];
			j++;
			index2[nums2[i]] -= 1;
			index1[nums2[i]] -= 1;
		}
		i++;
	}
	int *ret_arr = (int *)malloc(j * sizeof(int));
	*returnSize = j;
	i = 0;
	while (i < j)
	{
		ret_arr[i] = tab[i];
		i++;
	}
	free(tab);
	return ret_arr;
}
