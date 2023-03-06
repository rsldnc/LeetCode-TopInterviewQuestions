int firstMissingPositive(int *nums, int numsSize)
{
	int i;
	int pos;
	int tab[100002] = {0};

	i = 0;
	pos = 1;
	while (i < numsSize)
	{
		if (nums[i] > 0 && nums[i] <= 100000 && tab[nums[i]] == 0)
			tab[nums[i]] = 1;
		while (tab[pos] != 0 && pos <= 100000)
			pos++;
		i++;
	}
	return pos;
}
