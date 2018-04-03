	strbuf_release(&new_path);
}

static void show_man_page(const char *git_cmd)
{
	const char *page = cmd_to_page(git_cmd);
	setup_man_path();
	execlp("man", "man", page, NULL);
}

static void show_info_page(const char *git_cmd)