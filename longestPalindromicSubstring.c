bool isPalindrome(char *s, int beg, int end)
{
	int i = beg;
	int j = end;
	while (i < j)
	{
		if (i < j && s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

#include <stdlib.h>

char *longestPalindrome(char *s)
{
	int i = 0;
	int j;
	int size = 0;
	while (s[size])
		size++;
	int longp_size = 0 , longp_i = -1, longp_j = -1;
	while (s[i])
	{
		j = size - 1;
		while (i < j)
		{
			if (s[i] == s[j] && isPalindrome(s, i, j) && longp_size < j - i + 1)
			{
				longp_i = i;
				longp_j = j;
				longp_size = longp_j - longp_i + 1;
			}
			j--;
		}
		i++;
	}
	if (longp_i != -1)
	{
		char *ret_arr = (char *)malloc((longp_size + 1) * sizeof(char));
		int k = 0;
		while (longp_i <= longp_j)
		{
			ret_arr[k] = s[longp_i];
			k++;
			longp_i++;
		}
		ret_arr[k] = '\0';
		return ret_arr;
	}
	char *ret_arr = (char *)malloc(2 * sizeof(char));
	ret_arr[0] = s[0];
	ret_arr[1] = '\0';
	return ret_arr;
}
