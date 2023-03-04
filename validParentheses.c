#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int ft_findtype(char c) 
{
    if (c == '(')
    	return 0;
	else if (c == '{')
		return 1;
	else if (c == '[')
		return 2;
	else if (c == ')')
		return 3;
	else if (c == '}')
		return 4;
	else if (c == ']')
		return 5;
	return 0;
}

bool isValid(char* s) 
{
    int i = 0;
    int k = 0;
    int type;
	int len = strlen(s);
	char parentheses[] = { '(', '{', '[', ')', '}', ']' };
    char *validator = (char*)calloc(len, sizeof(char));
    
    if(s == NULL || len % 2 == 1) 
        return false;
    if (len == 0)
        return true;
    while (s[i]) 
	{
		type = ft_findtype(s[i]);
        if (type < 3) 
        	validator[k++] = s[i];
		else
		{
        	if (k > 0 && validator[k - 1] == parentheses[type - 3])
            	k--;
            else
                return false;
        }
        i++;
    }
    if (k == 0)
		return true;
	else
		return false; 
}
