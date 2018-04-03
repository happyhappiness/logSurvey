	strbuf_release(&new_path);
}

static void show_man_page(const char *git_cmd)
{
	struct man_viewer_list *viewer;
	const char *page = cmd_to_page(git_cmd);

	setup_man_path();
	for (viewer = man_viewer_list; viewer; viewer = viewer->next)
	{
		viewer->exec(page); /* will return when unable */
	}
	exec_man_man(page);
	die("no man viewer handled the request");
}

static void show_info_page(const char *git_cmd)