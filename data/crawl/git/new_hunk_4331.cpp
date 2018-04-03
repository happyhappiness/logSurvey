{
	strbuf_reset(&merge_msg);
	if (strbuf_read_file(&merge_msg, git_path("MERGE_MSG"), 0) < 0)
		die_errno(_("Could not read from '%s'"), git_path("MERGE_MSG"));
}

static void run_prepare_commit_msg(void)