	if (supported_man_viewer(name, len))
		do_add_man_viewer_info(name, len, value);
	else
		warning("'%s': path for unsupported man viewer.\n"
			"Please consider using 'man.<tool>.cmd' instead.",
			name);

	return 0;
}

static int add_man_viewer_cmd(const char *name,
			      size_t len,
			      const char *value)
{
	if (supported_man_viewer(name, len))
		warning("'%s': cmd for supported man viewer.\n"
			"Please consider using 'man.<tool>.path' instead.",
			name);
	else
		do_add_man_viewer_info(name, len, value);

	return 0;
}
