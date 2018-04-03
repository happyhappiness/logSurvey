	return 0;
}

static int read_file_or_gitlink(struct cache_entry *ce, struct strbuf *buf)
{
	if (!ce)
		return 0;

	if (S_ISGITLINK(ntohl(ce->ce_mode))) {
		strbuf_grow(buf, 100);
		strbuf_addf(buf, "Subproject commit %s\n", sha1_to_hex(ce->sha1));
	} else {
		enum object_type type;
		unsigned long sz;
		char *result;

		result = read_sha1_file(ce->sha1, &type, &sz);
		if (!result)
			return -1;
		/* XXX read_sha1_file NUL-terminates */
		strbuf_attach(buf, result, sz, sz + 1);
	}
	return 0;
}

static int apply_data(struct patch *patch, struct stat *st, struct cache_entry *ce)
{
	struct strbuf buf;

	strbuf_init(&buf, 0);
	if (cached) {
		if (read_file_or_gitlink(ce, &buf))
			return error("read of %s failed", patch->old_name);
	} else if (patch->old_name) {
		if (S_ISGITLINK(patch->old_mode)) {
			if (ce) {
				read_file_or_gitlink(ce, &buf);
			} else {
				/*
				 * There is no way to apply subproject
				 * patch without looking at the index.
				 */
				patch->fragments = NULL;
			}
		} else {
			if (read_old_data(st, patch->old_name, &buf))
				return error("read of %s failed", patch->old_name);
		}
	}

	if (apply_fragments(&buf, patch) < 0)
		return -1; /* note with --reject this succeeds. */
	patch->result = buf.buf;
	patch->resultsize = buf.len;

	if (0 < patch->is_delete && patch->resultsize)
		return error("removal patch leaves file contents");
