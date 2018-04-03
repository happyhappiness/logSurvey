
	if (patchbreak(line)) {
		if (mi->message_id)
			strbuf_addf(&mi->log_message,
				    "Message-Id: %s\n", mi->message_id);
		return 1;
	}

	strbuf_addbuf(&mi->log_message, line);
	return 0;
}

