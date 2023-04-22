bool canJump(int *nums, int numsSize)
{
	if (numsSize == 1 && nums[0] == 0)
		return true;
	int i = 0, j;
	while (i < numsSize - 1)
	{
		if (nums[i + 1] - nums[i] > nums[i])
		{
			j = i;
			while (j >= 0)
			{
				if (nums[j] - 1 >= i - j)
					break;
				j--;
			}
			if (j == -1)
				return false;
		}
		i++;
	}
	if (nums[numsSize - 1] == 0 && numsSize >= 2)
	{
		while (i >= 1)
		{
			if (nums[i - 1] >= (numsSize - 1) - (i - 1))
				break;
			i--;
		}
		if (i == 0)
			return false;
	}
	return true;
}
