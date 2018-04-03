	if (maybe_smart &&
	    (5 <= last->len && last->buf[4] == '#') &&
	    !strbuf_cmp(&exp, &type)) {
		char *line;

		/*
		 * smart HTTP response; validate that the service
		 * pkt-line matches our request.
		 */
		line = packet_read_line_buf(&last->buf, &last->len, NULL);

		strbuf_reset(&exp);
		strbuf_addf(&exp, "# service=%s", service);
		if (strcmp(line, exp.buf))
			die("invalid server response; got '%s'", line);
		strbuf_release(&exp);

		/* The header can include additional metadata lines, up
		 * until a packet flush marker.  Ignore these now, but
		 * in the future we might start to scan them.
		 */
		while (packet_read_line_buf(&last->buf, &last->len, NULL))
			;

		last->proto_git = 1;
	}
