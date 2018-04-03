		die("unrecognized command '%s'", argv[2]);
	} else {
		free(prog);
		die("invalid command format '%s'", argv[2]);
	}
}