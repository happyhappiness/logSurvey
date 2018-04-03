	finish_command(&ec_process);

	if (prefixcmp(buffer.buf, "emacsclient")) {
		strbuf_release(&buffer);
		return error("Failed to parse emacsclient version.");
	}

	strbuf_remove(&buffer, 0, strlen("emacsclient"));
	version = atoi(buffer.buf);

	if (version < 22) {
		strbuf_release(&buffer);
		return error("emacsclient version '%d' too old (< 22).",
			version);
	}

	strbuf_release(&buffer);