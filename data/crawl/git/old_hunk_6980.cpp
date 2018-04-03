		p = uq.buf;
	}

	if (inline_data) {
		static struct strbuf buf = STRBUF_INIT;

		if (p != uq.buf) {
