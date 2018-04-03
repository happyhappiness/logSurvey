		return 0;	/* error was already reported */

	if (strbuf_read(&nbuf, async.out, len) < 0) {
		err = error("read from external filter '%s' failed", cmd);
	}
	if (close(async.out)) {
		err = error("read from external filter '%s' failed", cmd);
	}
	if (finish_async(&async)) {
		err = error("external filter '%s' failed", cmd);
	}

	if (!err) {
		strbuf_swap(dst, &nbuf);
	}
	strbuf_release(&nbuf);
	return !err;
}

static struct convert_driver {