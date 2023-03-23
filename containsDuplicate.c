bool containsDuplicateForSmall(int *nums, int numsSize)
{
	int num;
	int i = 0;
	int j;
	while (i < numsSize)
	{
		num = nums[i];
		j = i + 1;
		while (j < numsSize)
		{
			if (nums[j] == num)
				return true;
			j++;
		}
		i++;
	}
	return false;
}

#include <stdlib.h>

bool containsDuplicateForBig(int *nums, int numsSize)
{
	int i = 1;
	int min = nums[0], max = nums[0];
	while (i < numsSize)
	{
		if (nums[i] < min)
			min = nums[i];
		if (nums[i] > max)
			max = nums[i];
		i++;
	}
	char *valid = calloc(max - min + 1, sizeof(char));
	i = 0;
	while (i < numsSize)
	{
		if (valid[nums[i] - min])
		{
			free(valid);
			return true;
		}
		else
			valid[nums[i] - min] = 1;
		i++;
	}
	free(valid);
	return false;
}

bool containsDuplicate(int *nums, int numsSize)
{
	if (numsSize < 100000 / 2)
	{
		if (containsDuplicateForSmall(nums, numsSize))
			return true;
		else
			return false;
	}
	else
	{
		if (containsDuplicateForBig(nums, numsSize))
			return true;
		else
			return false;
	}
}
