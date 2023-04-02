int lengthOfLongestSubstring(char *s)
{
	int i = 0, j, count, max_count = 0;
	while (s[i])
	{
		int index[256] = {0};
		count = 0;
		j = i;
		while (s[j] && index[s[j]] == 0)
		{
			index[s[j]] = 1;
			count++;
			j++;
		}
		if (count > max_count)
			max_count = count;
		if (s[j] == '\0')
			break;
		i++;
	}
	return max_count;
}
