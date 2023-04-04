int myAtoi(char *s)
{
	int	i = 0;
	long num = 0;
	int ae = 1;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			ae = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10;
		num = num + (s[i] - '0');
		i++;
		if((ae == -1 && num >= 2147483648) || (ae == -1 && num >= 300000000 && (s[i] >= '0' && s[i] <= '9')))
			return (-2147483648);
		else if ((ae == 1 && num >=2147483647) || (ae == 1 && num >= 300000000 && (s[i] >= '0' && s[i] <= '9')))
			return 2147483647;
	}
	return (num * ae);
}
