	for (; *argv; argv++) {
		char result[100];
		time_t t;

		result[0] = 0;
		parse_date(*argv, result, sizeof(result));
		t = strtoul(result, NULL, 0);
		printf("%s -> %s\n", *argv,
			t ? show_date(t, 0, DATE_ISO8601) : "bad");
	}
}
