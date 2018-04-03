		 */
		if (!need_to_gc())
			return 0;
		if (!quiet)
			fprintf(stderr,
					_("Auto packing the repository for optimum performance. You may also\n"
					"run \"git gc\" manually. See "
					"\"git help gc\" for more information.\n"));
	} else
		add_repack_all_option();

