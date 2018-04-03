	if (finish_command(&cp))
		die("git status --porcelain failed");

	strbuf_release(&buf);
	return dirty_submodule;
}
