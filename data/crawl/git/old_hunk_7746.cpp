		 */
		if (show_stage || show_unmerged)
			die("ls-files --with-tree is incompatible with -s or -u");
		overlay_tree(with_tree, prefix);
	}
	show_files(&dir, prefix);

	if (ps_matched) {
		/* We need to make sure all pathspec matched otherwise
		 * it is an error.
		 */
		int num, errors = 0;
		for (num = 0; pathspec[num]; num++) {
			int other, found_dup;

			if (ps_matched[num])
				continue;
			/*
			 * The caller might have fed identical pathspec
			 * twice.  Do not barf on such a mistake.
			 */
			for (found_dup = other = 0;
			     !found_dup && pathspec[other];
			     other++) {
				if (other == num || !ps_matched[other])
					continue;
				if (!strcmp(pathspec[other], pathspec[num]))
					/*
					 * Ok, we have a match already.
					 */
					found_dup = 1;
			}
			if (found_dup)
				continue;

			error("pathspec '%s' did not match any file(s) known to git.",
			      pathspec[num] + prefix_offset);
			errors++;
		}

		if (errors)
			fprintf(stderr, "Did you forget to 'git add'?\n");

		return errors ? 1 : 0;
	}

	return 0;
