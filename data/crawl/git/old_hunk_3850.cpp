	if (maybe_smart &&
	    (5 <= last->len && last->buf[4] == '#') &&
	    !strbuf_cmp(&exp, &type)) {
		/*
		 * smart HTTP response; validate that the service
		 * pkt-line matches our request.
		 */
		if (packet_get_line(&buffer, &last->buf, &last->len) <= 0)
			die("%s has invalid packet header", refs_url);
		if (buffer.len && buffer.buf[buffer.len - 1] == '\n')
			strbuf_setlen(&buffer, buffer.len - 1);

		strbuf_reset(&exp);
		strbuf_addf(&exp, "# service=%s", service);
		if (strbuf_cmp(&exp, &buffer))
			die("invalid server response; got '%s'", buffer.buf);
		strbuf_release(&exp);

		/* The header can include additional metadata lines, up
		 * until a packet flush marker.  Ignore these now, but
		 * in the future we might start to scan them.
		 */
		strbuf_reset(&buffer);
		while (packet_get_line(&buffer, &last->buf, &last->len) > 0)
			strbuf_reset(&buffer);

		last->proto_git = 1;
	}
