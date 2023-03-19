void reverseString(char *s, int sSize)
{
	char c;
	int i = 0;
	int len = sSize - 1;
	while (i < len)
	{
		c = s[i];
		s[i] = s[len];
		s[len] = c;
		i++;
		len--;
	}
}
