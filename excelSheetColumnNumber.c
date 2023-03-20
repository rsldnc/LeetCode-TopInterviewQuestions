int titleToNumber(char *columnTitle)
{
	int size = 0;
	while (columnTitle[size])
		size++;
	int i = 0;
	int c_num = 0;
	while (i < size)
	{
		c_num += columnTitle[i] - 64;
		if (i + 1 < size)
			c_num *= 26;
		i++;
	}
	return c_num;
}
