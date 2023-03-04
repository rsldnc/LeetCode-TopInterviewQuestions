#include <stdlib.h>

int	ft_strsize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int i;
	char *c;

	i = 0;
	c = (char *)malloc(ft_strsize(src) * sizeof(char) + 1);
	if (!c)
		return (NULL);
	while (src[i])
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char * longestCommonPrefix(char ** strs, int strsSize)
{
	int index[255] = {0};
	int i;
	int j;
	int k;
	int m;
	char *c = (char *)malloc(ft_strsize(strs[0]) * sizeof(char) + 1);
	
	i = 0;
	k = 0;
	m = 0;
	while (strs[0][k])
	{
    		i = 0;
		while (i < strsSize)
		{
			j = k;
			while (strs[i][j])
			{
				if (index[(int)strs[i][j]] == i)
        	    		{
    					index[(int)strs[i][j]] += 1;
				}
				break;
			}
			i++;
		}
		if (index[(int)strs[0][k]] == strsSize)
		{
			c[m] = strs[0][k];
			index[(int)strs[0][k]] = 0;
			m++;
		}
		else
			break;
		k++;
	}
	if (m != 0)
	{
		c[m] = '\0';
	}
	else
		return ("");
	char *arr = ft_strdup(c);
	return (arr);
}
