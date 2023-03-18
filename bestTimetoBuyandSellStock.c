int maxProfit(int *prices, int pricesSize)
{
	if (pricesSize == 1)
		return 0;
	int i = 1;
	int num, curr_profit;
	int profit = 0;
	int min = prices[0];
	while (i < pricesSize)
	{
		num = prices[i];
		curr_profit = num - min;
		
		if (curr_profit > profit)
			profit = curr_profit;
		if (num < min)
			min = num;
		i++;
	}
	return profit;
}
