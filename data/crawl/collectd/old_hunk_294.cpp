	}

	for (i = 0; i < values_num; i++)
		if (!isnan (values[i]))
			sum += values[i];

	if (sum == 0.0)
	{
