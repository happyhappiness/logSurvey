			cover_letter = 1;
		else if (!strcmp(argv[i], "--no-binary"))
			no_binary_diff = 1;
		else
			argv[j++] = argv[i];
	}
	argc = j;

	for (i = 0; i < extra_hdr_nr; i++) {
		strbuf_addstr(&buf, extra_hdr[i]);
		strbuf_addch(&buf, '\n');
