bool isAnagram(char *s, char *t)
{
	int index[256] = {0};
	int i = 0;
	while (s[i])
	{
		index[s[i]] += 1;
		i++;
	}
	i = 0;
	while (t[i])
	{
		index[t[i]] -= 1;
		i++;
	}
	i = 0;
	while (s[i] || t[i])
	{
		if (index[s[i]] != 0)
			return false;
		if (index[t[i]] != 0)
			return false;
		i++;
	}
	return true;
}
