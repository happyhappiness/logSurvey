		return 0;	/* error was already reported */

	if (strbuf_read(&nbuf, async.out, len) < 0) {
		error("read from external filter '%s' failed", cmd);
		ret = 0;
	}
	if (close(async.out)) {
		error("read from external filter '%s' failed", cmd);
		ret = 0;
	}
	if (finish_async(&async)) {
		error("external filter '%s' failed", cmd);
		ret = 0;
	}
