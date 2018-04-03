
		strbuf_reset(&result);
		parse_date(*argv, &result);
		if (sscanf(result.buf, "%"PRItime" %d", &t, &tz) == 2)
			printf("%s -> %s\n",
			       *argv, show_date(t, tz, DATE_MODE(ISO8601)));
		else
