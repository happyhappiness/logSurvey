			die("Unable to start %s, code %d", svndump_proc.argv[0], code);
		dumpin_fd = svndump_proc.out;
	}
	svndump_init_fd(dumpin_fd, STDIN_FILENO);
	svndump_read(url, private_ref);
	svndump_deinit();
