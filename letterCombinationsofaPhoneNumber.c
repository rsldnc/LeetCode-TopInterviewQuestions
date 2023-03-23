/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

char **letterCombinations(char *digits, int *returnSize)
{
	if (digits[0] == '\0')
	{
        *returnSize = 0;
        return NULL;
    }
	char digitletters[10][5] = {"rsl", "dnc", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
	int i = 0;
	int j = 0;
	int size = 1;
	while (digits[i])
	{
		j = 0;
		while (digitletters[digits[i] - '0'][j])
		{
			j++;
		}
		size = size * j;
		i++;
	}
	char **ret_arr = (char **)malloc(size * sizeof(char *));
	*returnSize = size;
	int row = 0;
	int a = 0;
	while (0 < i && digitletters[digits[0] - '0'][a])
	{
		int b = 0;
		while (1 < i && digitletters[digits[1] - '0'][b])
		{
			int c = 0;
			while (2 < i && digitletters[digits[2] - '0'][c])
			{
				int d = 0;
				while (3 < i && digitletters[digits[3] - '0'][d])
				{
					ret_arr[row] = (char *)malloc((i + 1) * sizeof(char));
					ret_arr[row][0] = digitletters[digits[0] - '0'][a];
					ret_arr[row][1] = digitletters[digits[1] - '0'][b];
					ret_arr[row][2] = digitletters[digits[2] - '0'][c];
					ret_arr[row][3] = digitletters[digits[3] - '0'][d];
					ret_arr[row][4] = '\0';
					row++;
					d++;					
				}
				if (i == 3)
				{
					ret_arr[row] = (char *)malloc((i + 1) * sizeof(char));
					ret_arr[row][0] = digitletters[digits[0] - '0'][a];
					ret_arr[row][1] = digitletters[digits[1] - '0'][b];
					ret_arr[row][2] = digitletters[digits[2] - '0'][c];
					ret_arr[row][3] = '\0';
					row++;
				}
				c++;
			}
			if (i == 2)
			{
				ret_arr[row] = (char *)malloc((i + 1) * sizeof(char));
				ret_arr[row][0] = digitletters[digits[0] - '0'][a];
				ret_arr[row][1] = digitletters[digits[1] - '0'][b];
				ret_arr[row][2] = '\0';
				row++;
			}
			b++;
		}
		if (i == 1)
		{
			ret_arr[row] = (char *)malloc((i + 1) * sizeof(char));
			ret_arr[row][0] = digitletters[digits[0] - '0'][a];
			ret_arr[row][1] = '\0';
			row++;
		}
		a++;
	}
	return ret_arr;
}
