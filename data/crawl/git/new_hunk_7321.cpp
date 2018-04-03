	else if (!strcasecmp(value, "konqueror"))
		do_add_man_viewer(exec_man_konqueror);
	else
		warning("'%s': unsupported man viewer.", value);

	return 0;
}