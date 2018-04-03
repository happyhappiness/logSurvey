	struct argv_array svndump_argv = ARGV_ARRAY_INIT;
	struct child_process svndump_proc;

	memset(&svndump_proc, 0, sizeof(struct child_process));
	svndump_proc.out = -1;
	argv_array_push(&svndump_argv, "svnrdump");
	argv_array_push(&svndump_argv, "dump");
	argv_array_push(&svndump_argv, url);
	argv_array_pushf(&svndump_argv, "-r%u:HEAD", startrev);
	svndump_proc.argv = svndump_argv.argv;

	code = start_command(&svndump_proc);
	if (code)
		die("Unable to start %s, code %d", svndump_proc.argv[0], code);
	dumpin_fd = svndump_proc.out;

	svndump_init_fd(dumpin_fd, STDIN_FILENO);
	svndump_read(url, private_ref);
	svndump_deinit();
	svndump_reset();

	close(dumpin_fd);
	code = finish_command(&svndump_proc);
	if (code)
		warning("%s, returned %d", svndump_proc.argv[0], code);
	argv_array_clear(&svndump_argv);

	return 0;
}
