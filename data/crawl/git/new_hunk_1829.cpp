		die_errno(_("Could not write to %s"), filename);
	strbuf_release(msgbuf);
	if (commit_lock_file(&msg_file) < 0)
		die(_("Error wrapping up %s."), filename);
}

static struct tree *empty_tree(void)