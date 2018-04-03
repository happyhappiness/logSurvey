	setup_man_path();
	for (viewer = man_viewer_list; viewer; viewer = viewer->next)
	{
		viewer->exec(page); /* will return when unable */
	}
	exec_man_man(page);
	die("no man viewer handled the request");
}
