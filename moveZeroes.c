void moveZeroes(int *nums, int numsSize)
{
	int	i;
	int	len;
	int	swap;

	len = numsSize - 1;
	while (len > 0)
	{
		i = 0;
		while (i < len)
		{
			if (nums[i] == 0)
			{
				swap = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = swap;
			}
			i++;
		}
		len--;
	}
}
