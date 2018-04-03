	struct strbuf err = STRBUF_INIT;
	int i, result = 0;

	if (repack_without_refs(refnames, &err))
		result |= error("%s", err.buf);
	strbuf_release(&err);

	for (i = 0; i < refnames->nr; i++) {
		const char *refname = refnames->items[i].string;
