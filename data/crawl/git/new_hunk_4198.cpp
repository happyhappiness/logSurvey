	}
}

int grep_source(struct grep_opt *opt, struct grep_source *gs)
{
	/*
	 * we do not have to do the two-pass grep when we do not check
	 * buffer-wide "all-match".
	 */
	if (!opt->all_match)
		return grep_source_1(opt, gs, 0);

	/* Otherwise the toplevel "or" terms hit a bit differently.
	 * We first clear hit markers from them.
	 */
	clr_hit_marker(opt->pattern_expression);
	grep_source_1(opt, gs, 1);

	if (!chk_hit_marker(opt->pattern_expression))
		return 0;

	return grep_source_1(opt, gs, 0);
}

int grep_buffer(struct grep_opt *opt, const char *name, char *buf, unsigned long size)
{
	struct grep_source gs;
	int r;

	grep_source_init(&gs, GREP_SOURCE_BUF, name, NULL);
	gs.buf = buf;
	gs.size = size;

	r = grep_source(opt, &gs);

	grep_source_clear(&gs);
	return r;
}

void grep_source_init(struct grep_source *gs, enum grep_source_type type,
		      const char *name, const void *identifier)
{
	gs->type = type;
	gs->name = name ? xstrdup(name) : NULL;
	gs->buf = NULL;
	gs->size = 0;

	switch (type) {
	case GREP_SOURCE_FILE:
		gs->identifier = xstrdup(identifier);
		break;
	case GREP_SOURCE_SHA1:
		gs->identifier = xmalloc(20);
		memcpy(gs->identifier, identifier, 20);
		break;
	case GREP_SOURCE_BUF:
		gs->identifier = NULL;
	}
}

void grep_source_clear(struct grep_source *gs)
{
	free(gs->name);
	gs->name = NULL;
	free(gs->identifier);
	gs->identifier = NULL;
	grep_source_clear_data(gs);
}

void grep_source_clear_data(struct grep_source *gs)
{
	switch (gs->type) {
	case GREP_SOURCE_FILE:
	case GREP_SOURCE_SHA1:
		free(gs->buf);
		gs->buf = NULL;
		gs->size = 0;
		break;
	case GREP_SOURCE_BUF:
		/* leave user-provided buf intact */
		break;
	}
}

static int grep_source_load_sha1(struct grep_source *gs)
{
	enum object_type type;

	grep_read_lock();
	gs->buf = read_sha1_file(gs->identifier, &type, &gs->size);
	grep_read_unlock();

	if (!gs->buf)
		return error(_("'%s': unable to read %s"),
			     gs->name,
			     sha1_to_hex(gs->identifier));
	return 0;
}

static int grep_source_load_file(struct grep_source *gs)
{
	const char *filename = gs->identifier;
	struct stat st;
	char *data;
	size_t size;
	int i;

	if (lstat(filename, &st) < 0) {
	err_ret:
		if (errno != ENOENT)
			error(_("'%s': %s"), filename, strerror(errno));
		return -1;
	}
	if (!S_ISREG(st.st_mode))
		return -1;
	size = xsize_t(st.st_size);
	i = open(filename, O_RDONLY);
	if (i < 0)
		goto err_ret;
	data = xmalloc(size + 1);
	if (st.st_size != read_in_full(i, data, size)) {
		error(_("'%s': short read %s"), filename, strerror(errno));
		close(i);
		free(data);
		return -1;
	}
	close(i);
	data[size] = 0;

	gs->buf = data;
	gs->size = size;
	return 0;
}

int grep_source_load(struct grep_source *gs)
{
	if (gs->buf)
		return 0;

	switch (gs->type) {
	case GREP_SOURCE_FILE:
		return grep_source_load_file(gs);
	case GREP_SOURCE_SHA1:
		return grep_source_load_sha1(gs);
	case GREP_SOURCE_BUF:
		return gs->buf ? 0 : -1;
	}
	die("BUG: invalid grep_source type");
}
