int majorityElement(int *nums, int numsSize)
{
	int num;
	int i = 0;
	int j;
	int times;
	while (i < numsSize)
	{
		while (nums[i] > 1000000000)
			i++;
		num = nums[i];
		times = 0;
		j = i;
		while (j < numsSize)
		{
			if (nums[j] == num)
			{
				times++;
				nums[j] = 1000000001;			
			}
			j++;
		}
		if (times > numsSize / 2)
			return num;
		i++;
	}
	return 0;
}
