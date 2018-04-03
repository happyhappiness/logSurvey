	return strbuf_detach(&helpbuf, NULL);
}

static void write_message(struct strbuf *msgbuf, const char *filename)
{
	static struct lock_file msg_file;

	int msg_fd = hold_lock_file_for_update(&msg_file, filename,
					       LOCK_DIE_ON_ERROR);
	if (write_in_full(msg_fd, msgbuf->buf, msgbuf->len) < 0)
		die_errno("Could not write to %s.", filename);
	strbuf_release(msgbuf);
	if (commit_lock_file(&msg_file) < 0)
		die("Error wrapping up %s", filename);
}

static struct tree *empty_tree(void)
{
	struct tree *tree = xcalloc(1, sizeof(struct tree));
