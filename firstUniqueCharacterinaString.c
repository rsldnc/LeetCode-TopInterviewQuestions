int firstUniqChar(char *s)
{
	int index[256] = {0};
	int i = 0;
	while (s[i])
	{
		index[s[i]] += 1;
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (index[s[i]] == 1)
			return i;
		i++;
	}
	return -1;
}
