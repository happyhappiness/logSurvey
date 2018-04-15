	total_num = 0;
	for (i = 0; i < values_num; i++)
	{
		if (!isnan (values[i]))
		{
			total += values[i];
			total_num++;
		}
	}

	if (total_num == 0)
