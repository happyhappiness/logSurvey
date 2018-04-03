		 * pkt-line matches our request.
		 */
		line = packet_read_line_buf(&last->buf, &last->len, NULL);
		if (!line)
			die("invalid server response; expected service, got flush packet");

		strbuf_reset(&exp);
		strbuf_addf(&exp, "# service=%s", service);
