	if (!path)
		path = "man";
	execlp(path, "man", page, (char *)NULL);
	warning(_("failed to exec '%s': %s"), path, strerror(errno));
}

static void exec_man_cmd(const char *cmd, const char *page)
{
	struct strbuf shell_cmd = STRBUF_INIT;
	strbuf_addf(&shell_cmd, "%s %s", cmd, page);
	execl(SHELL_PATH, SHELL_PATH, "-c", shell_cmd.buf, (char *)NULL);
	warning(_("failed to exec '%s': %s"), cmd, strerror(errno));
}

static void add_man_viewer(const char *name)