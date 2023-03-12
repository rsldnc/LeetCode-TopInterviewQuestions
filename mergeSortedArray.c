void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
	int i;
	int len;
	int temp;
	
	i = 0;
	len = m + n;
	while (i < n)
	{
		nums1[m + i] = nums2[i];
		i++;
	}
	while (len > 0)
	{
		i = 0;
		while (i < len - 1)
		{
			if (nums1[i] > nums1[i + 1])
			{
				temp = nums1[i];
				nums1[i] = nums1[i + 1];
				nums1[i + 1] = temp;
			}
			i++;
		}
		len--;
	}
	nums1Size = m + n;
	nums2Size = n;
}
