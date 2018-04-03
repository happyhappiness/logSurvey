	return 0;
}

static void exec_woman_emacs(const char *page)
{
	if (!check_emacsclient_version()) {
		/* This works only with emacsclient version >= 22. */
		struct strbuf man_page = STRBUF_INIT;
		strbuf_addf(&man_page, "(woman \"%s\")", page);
		execlp("emacsclient", "emacsclient", "-e", man_page.buf, NULL);
	}
}

static void exec_man_konqueror(const char *page)
{
	const char *display = getenv("DISPLAY");
	if (display && *display) {
		struct strbuf man_page = STRBUF_INIT;
		strbuf_addf(&man_page, "man:%s(1)", page);
		execlp("kfmclient", "kfmclient", "newTab", man_page.buf, NULL);
	}
}

static void exec_man_man(const char *page)
{
	execlp("man", "man", page, NULL);
}

static void do_add_man_viewer(void (*exec)(const char *))
{
	struct man_viewer_list **p = &man_viewer_list;

	while (*p)
		p = &((*p)->next);
	*p = xmalloc(sizeof(**p));
	(*p)->next = NULL;
	(*p)->exec = exec;
}

static int add_man_viewer(const char *value)
{
	if (!strcasecmp(value, "man"))
		do_add_man_viewer(exec_man_man);
	else if (!strcasecmp(value, "woman"))
		do_add_man_viewer(exec_woman_emacs);
	else if (!strcasecmp(value, "konqueror"))
		do_add_man_viewer(exec_man_konqueror);
	else
		warning("'%s': unsupported man viewer.", value);

	return 0;
}

static int git_help_config(const char *var, const char *value)
{
	if (!strcmp(var, "help.format")) {
