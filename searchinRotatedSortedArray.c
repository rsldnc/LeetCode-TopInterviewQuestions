int search(int *nums, int numsSize, int target)
{
	int i = 0;
	if (nums[0] < nums[numsSize / 2] && nums[numsSize / 2] < nums[numsSize - 1] && nums[numsSize / 2] < target)
		i = numsSize / 2;
	while (i < numsSize)
	{
		if (nums[i] == target)
			return i;
		i++;
	}
	return -1;
}
