		operating_mode = MODE_SERVER;
	else if (strcasecmp (value, "Local") == 0)
		operating_mode = MODE_LOCAL;
#endif
	else if (strcasecmp (value, "Log") == 0)
		operating_mode = MODE_LOG;