int removeDuplicates(int *nums, int numsSize)
{
	int i;
	int temp;
	int k;
	int last = numsSize - 1;
	int tab[201] = {0};
	
	i = 0;
	k = 0;
	while (i < numsSize)
	{
		while (i < last && ((nums[i] < 0 && tab[nums[i] + 201] == 1) || (nums[i] >= 0 && tab[nums[i]] == 1)))
		{
			if (nums[last] < 0 && tab[nums[last] + 201] == 0)
			{
				temp = nums[i];
				nums[i] = nums[last];
				nums[last] = temp;
				break;
			}
			else if (nums[last] >= 0 && tab[nums[last]] == 0)
			{
				temp = nums[i];
				nums[i] = nums[last];
				nums[last] = temp;
				break;
			}
			last--;
		}
		if (nums[i] < 0 && tab[nums[i] + 201] == 0)
		{
			tab[nums[i] + 201] = 1;
			k++;			
		}
		else if (nums[i] >= 0 && tab[nums[i]] == 0)
		{
			tab[nums[i]] = 1;
			k++;			
		}
		i++;
	}
	int len = k - 1;
	while (len > 0)
	{
		i = 0;
		while (i < len)
		{
			if (nums[i] > nums[i + 1])
			{
				temp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = temp;
			}
			i++;
		}
		len--;
	}
	return k;
}
