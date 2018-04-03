	}
}

static int write_message(struct strbuf *msgbuf, const char *filename)
{
	static struct lock_file msg_file;

	int msg_fd = hold_lock_file_for_update(&msg_file, filename, 0);
	if (msg_fd < 0)
		return error_errno(_("Could not lock '%s'"), filename);
	if (write_in_full(msg_fd, msgbuf->buf, msgbuf->len) < 0)
		return error_errno(_("Could not write to %s"), filename);
	strbuf_release(msgbuf);
	if (commit_lock_file(&msg_file) < 0)
		return error(_("Error wrapping up %s."), filename);

	return 0;
}

static struct tree *empty_tree(void)
