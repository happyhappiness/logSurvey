	} else if ((!o_sha && a_sha && !b_sha) ||
		   (!o_sha && !a_sha && b_sha)) {
		/* Case B: Added in one. */
		unsigned mode;
		const unsigned char *sha;

		if (a_sha) {
			mode = a_mode;
			sha = a_sha;
		} else {
			mode = b_mode;
			sha = b_sha;
		}
		if (string_list_has_string(&o->current_directory_set, path)) {
			/* Handle D->F conflicts after all subfiles */
			entry->processed = 0;
			/* But get any file out of the way now, so conflicted
			 * entries below the directory of the same name can
			 * be put in the working directory.
			 */
			if (a_sha)
				output(o, 2, "Removing %s", path);
			/* do not touch working file if it did not exist */
			remove_file(o, 0, path, !a_sha);
			return 1; /* Assume clean till processed */
		} else {
			output(o, 2, "Adding %s", path);
			update_file(o, 1, sha, mode, path);
