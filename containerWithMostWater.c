int maxArea(int *height, int heightSize)
{
	if (heightSize == 1)
		return height[0];
	int left = 0;
	int right = heightSize - 1; 
	int curr_area = 0, max_area = 0;
	while (left < right)
	{
		curr_area = (right - left) * (height[right] > height[left] ? height[left] : height[right]);
		if (curr_area > max_area)
			max_area = curr_area;
		if (height[right] > height[left])
			left++;
		else
			right--;
	}
	return max_area;
}
