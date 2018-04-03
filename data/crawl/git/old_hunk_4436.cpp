		;

	if (i + 2 >= max_length)
		die("Too many options specified");
	cmd[i++] = opt;
	cmd[i] = NULL;
}
