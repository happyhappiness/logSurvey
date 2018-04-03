	if (!socket_path)
		usage_with_options(usage, options);

	init_socket_directory(socket_path);
	register_tempfile(&socket_file, socket_path);
