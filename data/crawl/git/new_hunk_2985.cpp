	die_errno(_("could not read '%s'"), am_path(state, file));
}

/**
 * Reads a KEY=VALUE shell variable assignment from `fp`, returning the VALUE
 * as a newly-allocated string. VALUE must be a quoted string, and the KEY must
 * match `key`. Returns NULL on failure.
 *
 * This is used by read_author_script() to read the GIT_AUTHOR_* variables from
 * the author-script.
 */
static char *read_shell_var(FILE *fp, const char *key)
{
	struct strbuf sb = STRBUF_INIT;
	const char *str;

	if (strbuf_getline(&sb, fp, '\n'))
		goto fail;

	if (!skip_prefix(sb.buf, key, &str))
		goto fail;

	if (!skip_prefix(str, "=", &str))
		goto fail;

	strbuf_remove(&sb, 0, str - sb.buf);

	str = sq_dequote(sb.buf);
	if (!str)
		goto fail;

	return strbuf_detach(&sb, NULL);

fail:
	strbuf_release(&sb);
	return NULL;
}

/**
 * Reads and parses the state directory's "author-script" file, and sets
 * state->author_name, state->author_email and state->author_date accordingly.
 * Returns 0 on success, -1 if the file could not be parsed.
 *
 * The author script is of the format:
 *
 *	GIT_AUTHOR_NAME='$author_name'
 *	GIT_AUTHOR_EMAIL='$author_email'
 *	GIT_AUTHOR_DATE='$author_date'
 *
 * where $author_name, $author_email and $author_date are quoted. We are strict
 * with our parsing, as the file was meant to be eval'd in the old git-am.sh
 * script, and thus if the file differs from what this function expects, it is
 * better to bail out than to do something that the user does not expect.
 */
static int read_author_script(struct am_state *state)
{
	const char *filename = am_path(state, "author-script");
	FILE *fp;

	assert(!state->author_name);
	assert(!state->author_email);
	assert(!state->author_date);

	fp = fopen(filename, "r");
	if (!fp) {
		if (errno == ENOENT)
			return 0;
		die_errno(_("could not open '%s' for reading"), filename);
	}

	state->author_name = read_shell_var(fp, "GIT_AUTHOR_NAME");
	if (!state->author_name) {
		fclose(fp);
		return -1;
	}

	state->author_email = read_shell_var(fp, "GIT_AUTHOR_EMAIL");
	if (!state->author_email) {
		fclose(fp);
		return -1;
	}

	state->author_date = read_shell_var(fp, "GIT_AUTHOR_DATE");
	if (!state->author_date) {
		fclose(fp);
		return -1;
	}

	if (fgetc(fp) != EOF) {
		fclose(fp);
		return -1;
	}

	fclose(fp);
	return 0;
}

/**
 * Saves state->author_name, state->author_email and state->author_date in the
 * state directory's "author-script" file.
 */
static void write_author_script(const struct am_state *state)
{
	struct strbuf sb = STRBUF_INIT;

	strbuf_addstr(&sb, "GIT_AUTHOR_NAME=");
	sq_quote_buf(&sb, state->author_name);
	strbuf_addch(&sb, '\n');

	strbuf_addstr(&sb, "GIT_AUTHOR_EMAIL=");
	sq_quote_buf(&sb, state->author_email);
	strbuf_addch(&sb, '\n');

	strbuf_addstr(&sb, "GIT_AUTHOR_DATE=");
	sq_quote_buf(&sb, state->author_date);
	strbuf_addch(&sb, '\n');

	write_file(am_path(state, "author-script"), 1, "%s", sb.buf);

	strbuf_release(&sb);
}

/**
 * Reads the commit message from the state directory's "final-commit" file,
 * setting state->msg to its contents and state->msg_len to the length of its
 * contents in bytes.
 *
 * Returns 0 on success, -1 if the file does not exist.
 */
static int read_commit_msg(struct am_state *state)
{
	struct strbuf sb = STRBUF_INIT;

	assert(!state->msg);

	if (read_state_file(&sb, state, "final-commit", 0) < 0) {
		strbuf_release(&sb);
		return -1;
	}

	state->msg = strbuf_detach(&sb, &state->msg_len);
	return 0;
}

/**
 * Saves state->msg in the state directory's "final-commit" file.
 */
static void write_commit_msg(const struct am_state *state)
{
	int fd;
	const char *filename = am_path(state, "final-commit");

	fd = xopen(filename, O_WRONLY | O_CREAT, 0666);
	if (write_in_full(fd, state->msg, state->msg_len) < 0)
		die_errno(_("could not write to %s"), filename);
	close(fd);
}

/**
 * Loads state from disk.
 */
