	else if (0 == strcasecmp (key, "MaxConns")) {
		long int tmp = strtol (value, NULL, 0);

		if (INT_MAX < tmp) {
			max_conns = INT_MAX;
		}
		else {
			max_conns = (int)tmp;