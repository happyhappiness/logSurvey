	return 0;
}

static int read_file_or_gitlink(struct cache_entry *ce, char **buf_p,
				unsigned long *size_p)
{
	if (!ce)
		return 0;

	if (S_ISGITLINK(ntohl(ce->ce_mode))) {
		*buf_p = xmalloc(100);
		*size_p = snprintf(*buf_p, 100,
			"Subproject commit %s\n", sha1_to_hex(ce->sha1));
	} else {
		enum object_type type;
		*buf_p = read_sha1_file(ce->sha1, &type, size_p);
		if (!*buf_p)
			return -1;
	}
	return 0;
}

static int apply_data(struct patch *patch, struct stat *st, struct cache_entry *ce)
{
	char *buf;
	unsigned long size, alloc;
	struct buffer_desc desc;

	size = 0;
	alloc = 0;
	buf = NULL;
	if (cached) {
		if (read_file_or_gitlink(ce, &buf, &size))
			return error("read of %s failed", patch->old_name);
		alloc = size;
	} else if (patch->old_name) {
		if (S_ISGITLINK(patch->old_mode)) {
			if (ce)
				read_file_or_gitlink(ce, &buf, &size);
			else {
				/*
				 * There is no way to apply subproject
				 * patch without looking at the index.
				 */
				patch->fragments = NULL;
				size = 0;
			}
		}
		else {
			size = xsize_t(st->st_size);
			alloc = size + 8192;
			buf = xmalloc(alloc);
			if (read_old_data(st, patch->old_name,
					  &buf, &alloc, &size))
				return error("read of %s failed",
					     patch->old_name);
		}
	}

	desc.size = size;
	desc.alloc = alloc;
	desc.buffer = buf;

	if (apply_fragments(&desc, patch) < 0)
		return -1; /* note with --reject this succeeds. */

	/* NUL terminate the result */
	if (desc.alloc <= desc.size)
		desc.buffer = xrealloc(desc.buffer, desc.size + 1);
	desc.buffer[desc.size] = 0;

	patch->result = desc.buffer;
	patch->resultsize = desc.size;

	if (0 < patch->is_delete && patch->resultsize)
		return error("removal patch leaves file contents");
