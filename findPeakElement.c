int findPeakElement(int *nums, int numsSize)
{
	if (numsSize == 1)
		return 0;
	int i = 0;
	while (i < numsSize)
	{
		if (i == 0 && nums[i] > nums[i + 1])
			return i;
		else if (i == numsSize - 1 && nums[i] > nums[i - 1])
			return i;
		else if (i > 0 && i + 1 < numsSize && nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
			return i;
		else
			i++;
	}
	return -1;
}
