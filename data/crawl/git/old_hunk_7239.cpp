	if (supported_man_viewer(name, len))
		do_add_man_viewer_info(name, len, value);
	else
		warning("'%s': path for unsupported man viewer.", name);

	return 0;
}
