		 */
		if (!need_to_gc())
			return 0;
		if (quiet)
			fprintf(stderr, _("Auto packing the repository for optimum performance.\n"));
		else
			fprintf(stderr,
					_("Auto packing the repository for optimum performance. You may also\n"
					"run \"git gc\" manually. See "
					"\"git help gc\" for more information."));
	} else
		append_option(argv_repack,
			      prune_expire && !strcmp(prune_expire, "now")