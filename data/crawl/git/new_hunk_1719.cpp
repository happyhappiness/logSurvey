
}

static void read_merge_msg(struct strbuf *msg)
{
	const char *filename = git_path_merge_msg();
