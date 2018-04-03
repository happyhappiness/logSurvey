
	if (mi->use_scissors && is_scissors_line(line)) {
		int i;

		strbuf_setlen(&mi->log_message, 0);
		mi->header_stage = 1;

		/*
