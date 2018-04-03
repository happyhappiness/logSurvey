		 */
		if (!need_to_gc())
			return 0;
		fprintf(stderr, "Auto packing your repository for optimum "
			"performance. You may also\n"
			"run \"git gc\" manually. See "
			"\"git help gc\" for more information.\n");
	} else
		append_option(argv_repack,
			      prune_expire && !strcmp(prune_expire, "now")