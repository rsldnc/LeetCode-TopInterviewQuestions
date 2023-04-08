#include <stdlib.h>

int trap(int *height, int heightSize)
{
	int units = 0;
	int *left_border = (int *)malloc(heightSize * sizeof(int));
	int *right_border = (int *)malloc(heightSize * sizeof(int));
	
	left_border[0] = height[0];
	right_border[heightSize - 1] = height[heightSize - 1];
	
	int i = 1, j = heightSize - 2;
	while (i < heightSize && j >= 0)
	{
		if (height[i] > left_border[i - 1])
			left_border[i] = height[i];
		else
			left_border[i] = left_border[i - 1];
		if (height[j] > right_border[j + 1])
			right_border[j] = height[j];
		else
			right_border[j] = right_border[j + 1];
		i++;
		j--;
	}
	int min_border = 0;
	i = 0;
	while (i < heightSize)
	{
		if (left_border[i] < right_border[i])
			min_border = left_border[i];
		else
			min_border = right_border[i];
		if (min_border > height[i])
			units += min_border - height[i];
		i++;
	}
	free(left_border);
	free(right_border);
	return units;
}
