	strbuf_release(&sb);
}

unsigned is_submodule_modified(const char *path, int ignore_untracked)
{
	ssize_t len;
