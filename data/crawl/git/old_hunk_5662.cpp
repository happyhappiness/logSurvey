		ps_matched = xcalloc(1, num);
	}

	if ((dir.flags & DIR_SHOW_IGNORED) && !exc_given) {
		fprintf(stderr, "%s: --ignored needs some exclude pattern\n",
			argv[0]);
		exit(1);
	}

	/* With no flags, we default to showing the cached files */
	if (!(show_stage | show_deleted | show_others | show_unmerged |