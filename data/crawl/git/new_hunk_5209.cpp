	char *defmsg = NULL;
	struct strbuf msgbuf = STRBUF_INIT;

	if (no_commit) {
		/*
		 * We do not intend to commit immediately.  We just want to
