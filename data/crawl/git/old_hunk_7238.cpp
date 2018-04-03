		!strncasecmp("konqueror", name, len));
}

static int add_man_viewer(const char *value)
{
	if (supported_man_viewer(value, strlen(value)))
		do_add_man_viewer(value);
	else
		warning("'%s': unsupported man viewer.", value);

	return 0;
}

static void do_add_man_viewer_info(const char *name,
				   size_t len,
				   const char *value)
