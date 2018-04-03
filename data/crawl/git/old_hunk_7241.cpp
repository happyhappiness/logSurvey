
static void exec_viewer(const char *name, const char *page)
{
	const char *path = get_man_viewer_info(name);

	if (!strcasecmp(name, "man"))
		exec_man_man(path, page);
	else if (!strcasecmp(name, "woman"))
		exec_woman_emacs(path, page);
	else if (!strcasecmp(name, "konqueror"))
		exec_man_konqueror(path, page);
	else
		warning("'%s': unsupported man viewer.", name);
}

static void show_man_page(const char *git_cmd)