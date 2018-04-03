	warning("failed to exec '%s': %s", path, strerror(errno));
}

static void do_add_man_viewer(const char *name)
{
	struct man_viewer_list **p = &man_viewer_list;
	size_t len = strlen(name);
