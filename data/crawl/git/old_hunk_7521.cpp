	execlp("info", "info", "gitman", page, NULL);
}

static void show_html_page(const char *git_cmd)
{
	const char *page = cmd_to_page(git_cmd);
	execl_git_cmd("help--browse", page, NULL);
}

void help_unknown_cmd(const char *cmd)