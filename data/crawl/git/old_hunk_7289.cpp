		 * to emulate by hand - much easier to let the system
		 * just do the right thing)
		 */
		unlink(path);
		if (S_ISDIR(st.st_mode)) {
			/* If it is a gitlink, leave it alone! */
			if (S_ISGITLINK(ce->ce_mode))
				return 0;
			if (!state->force)
				return error("%s is a directory", path);
			remove_subtree(path);
		}
	} else if (state->not_new)
		return 0;
	create_directories(path, state);