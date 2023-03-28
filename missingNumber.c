int missingNumber(int *nums, int numsSize)
{
	int tab[10001] = {0};
	int i = 0;
	while (i < numsSize)
	{
		tab[nums[i]] = 1;
		i++;
	}
	i = 0;
	while (i < numsSize)
	{
		if (tab[i] == 0)
			return i;
		i++;
	}
	return numsSize;
}
