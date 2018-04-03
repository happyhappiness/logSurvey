	strbuf_release(&buf);
}

static void show_dates(char **argv, const char *format)
{
	struct date_mode mode;

	parse_date_format(format, &mode);
	for (; *argv; argv++) {
		char *arg = *argv;
		time_t t;
		int tz;

		/*
		 * Do not use our normal timestamp parsing here, as the point
		 * is to test the formatting code in isolation.
		 */
		t = strtol(arg, &arg, 10);
		while (*arg == ' ')
			arg++;
		tz = atoi(arg);

		printf("%s -> %s\n", *argv, show_date(t, tz, &mode));
	}
}

static void parse_dates(char **argv, struct timeval *now)
{
	struct strbuf result = STRBUF_INIT;
