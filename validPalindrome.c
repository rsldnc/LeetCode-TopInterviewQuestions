int isAlphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    	return 1;
    else
    	return 0;
}

char	*ft_strlowcase(char *str)
{
	int	i;
	int	x;

	x = 'a' - 'A';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + x;
		i++;
	}
	return (str);
}

bool isPalindrome(char *s)
{
	int size = 0;
	int i = 0;
	while (s[size])
		size++;
	int j = size - 1;
	ft_strlowcase(s);
	while (i < j)
	{
		while (i < size && !(isAlphanumeric(s[i])))
			i++;
		while (j >= 0 && !(isAlphanumeric(s[j])))
			j--;
		if (i < j && s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}
