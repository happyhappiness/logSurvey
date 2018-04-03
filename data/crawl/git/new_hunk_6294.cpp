		}
		else if (!strcmp(argv[i], "--signoff") ||
			 !strcmp(argv[i], "-s")) {
			do_signoff = 1;
		}
		else if (!strcmp(argv[i], "--attach")) {
			rev.mime_boundary = git_version_string;
