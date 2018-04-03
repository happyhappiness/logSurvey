	strbuf_release(&path);
}

static void separate_git_dir(const char *git_dir)
{
	struct stat st;
