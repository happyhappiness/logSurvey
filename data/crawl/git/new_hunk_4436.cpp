		;

	if (i + 2 >= max_length)
		die(_("Too many options specified"));
	cmd[i++] = opt;
	cmd[i] = NULL;
}
