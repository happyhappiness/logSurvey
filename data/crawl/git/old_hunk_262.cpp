		die("socket directory must be an absolute path");

	init_socket_directory(socket_path);
	register_tempfile(&socket_file, socket_path);

	if (ignore_sighup)
		signal(SIGHUP, SIG_IGN);
