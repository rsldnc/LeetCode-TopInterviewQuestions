#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int i, j, z;
	int cnbr = nbr;
	char *num;
	
	i = 0;
	while (nbr)
	{
		i++;
		nbr = nbr / 10;
	}
	num = (char *)malloc(i * sizeof(char) + 1);
	j = i - 1;
	while (cnbr)
	{
		num[j] = (cnbr % 10) + '0';
		j--;
		cnbr = cnbr / 10;
	}
	num[i] = '\0';
	return (num);
}

void reverseString(char *s)
{
	char c;
	int sSize = 0;
	while (s[sSize])
		sSize++;
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
			return (0);
		else if ((ae == 1 && num >=2147483647) || (ae == 1 && num >= 300000000 && (s[i] >= '0' && s[i] <= '9')))
			return (0);
	}
	return (num * ae);
}
int reverse(int x)
{
	if (x == 0)
		return x;
	if (x == -2147483648)
		return 0;
	int ae = 1;
	if (x < 0)
	{
		ae = -1;
		x = x * -1;
	}
	char *num = ft_itoa(x);
	reverseString(num);
	long r_num = myAtoi(num);
	if (ae == -1)
		return r_num * -1;
	else
		return r_num;
}
