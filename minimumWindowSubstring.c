#include <stdlib.h>

char	*ft_strndup(char *src, int begin_index, int n)
{
	int i;
	char	*c;

	i = 0;
	c = (char *)malloc((n + 1) * sizeof(char));
	if (!c)
		return (NULL);
	while (i < n)
	{
		c[i] = src[begin_index];
		i++;
		begin_index++;
	}
	c[i] = '\0';
	return (c);
}

char *minWindow(char *s, char *t)
{
	int len_t = 0;
	while (t[len_t])
		len_t++;
	int len_s = 0;
	while (s[len_s])
		len_s++;
	if (len_s < len_t)
		return "";

	int index_t[256] = {0};
	int uniqc_t = 0;
	int i = 0;
	while (i < len_t)
	{
		index_t[t[i]] += 1;
		if (index_t[t[i]] == 1)
			uniqc_t++;
		i++;
	}
	
	int index_s[256] = {0};
	int len_min = len_s + 1, beg_min = 0;
	i = 0;
	int j = 0, counter = 0;
	while (s[i])
	{
		if (index_t[s[i]] > 0)
		{
			index_s[s[i]] += 1;
			if (index_s[s[i]] == index_t[s[i]])
				counter++;
		}
		i++;
		while (counter == uniqc_t)
		{
			if (i - j < len_min)
			{
				len_min = i - j;
				beg_min = j;
			}
			if (index_t[s[j]] > 0)
			{
				index_s[s[j]] -= 1;
				if (index_s[s[j]] < index_t[s[j]])
					counter--;
			}
			j++;
		}
	}
	if (len_min == len_s + 1)
		return "";
	return ft_strndup(s, beg_min, len_min);
}
