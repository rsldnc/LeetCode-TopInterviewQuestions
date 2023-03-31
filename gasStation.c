int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
	int j = 0;
	int beststart_index = 0;
	int max_dif = 0, curr_dif, total_dif = 0;
	while (j < gasSize)
	{
		curr_dif = gas[j] - cost[j];
		total_dif += curr_dif;
		if (curr_dif > max_dif)
		{
			max_dif = curr_dif;
			beststart_index = j;
		}
		j++;
	}
	if (total_dif < 0)
		return -1;
	int start_index = beststart_index;
	int i, tank, times, times2 = 0;
	while (start_index < gasSize)
	{
		tank = 0;
		times = 0;
		i = start_index;
		while (1)
		{
			tank += gas[i];
			tank -= cost[i];
			if (tank < 0)
				break;
			i++;
			times++;
			if (i == start_index)
				break;
			if (i == gasSize)
			{
				if (times == gasSize)
					break;
				else
					i = 0;
			}
		}
		if (tank >= 0)
			return start_index;
		start_index++;
		times2++;
		if (start_index == gasSize && times2 != gasSize)
			start_index = 0;
		if (times2 == gasSize)
			break;
	}
	return -1;
}
