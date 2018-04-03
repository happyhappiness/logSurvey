	}
	argc = j;

	for (i = 0; i < extra_hdr_nr; i++) {
		strbuf_addstr(&buf, extra_hdr[i]);
		strbuf_addch(&buf, '\n');