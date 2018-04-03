	for (; *argv; argv++) {
		char result[100];
		time_t t;
		int tz;

		result[0] = 0;
		parse_date(*argv, result, sizeof(result));
		if (sscanf(result, "%ld %d", &t, &tz) == 2)
			printf("%s -> %s\n",
			       *argv, show_date(t, tz, DATE_ISO8601));
		else
			printf("%s -> bad\n", *argv);
	}
}
