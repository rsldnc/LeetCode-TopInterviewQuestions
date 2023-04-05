#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p) 
{
	int s_len = 0, p_len = 0;
	while (s[s_len])
		s_len++;
	while (p[p_len])
		p_len++;
	bool validator[s_len + 1][p_len + 1];
	memset(validator, false, sizeof(validator));
	validator[0][0] = true;
	int i = 0;
	while (i <= s_len)
	{
		int j = 1;
		while (j <= p_len)
		{
			if (p[j - 1] == '*')
				validator[i][j] = validator[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && validator[i - 1][j]);
			else
				validator[i][j] = i > 0 && validator[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			j++;
		}
		i++;
	}
	return validator[s_len][p_len];
}
