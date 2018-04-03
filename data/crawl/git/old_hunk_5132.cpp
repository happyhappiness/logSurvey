	} else if ((!o_sha && a_sha && !b_sha) ||
		   (!o_sha && !a_sha && b_sha)) {
		/* Case B: Added in one. */
		const char *add_branch;
		const char *other_branch;
		unsigned mode;
		const unsigned char *sha;
		const char *conf;

		if (a_sha) {
			add_branch = o->branch1;
			other_branch = o->branch2;
			mode = a_mode;
			sha = a_sha;
			conf = "file/directory";
		} else {
			add_branch = o->branch2;
			other_branch = o->branch1;
			mode = b_mode;
			sha = b_sha;
			conf = "directory/file";
		}
		if (string_list_has_string(&o->current_directory_set, path)) {
			const char *new_path = unique_path(o, path, add_branch);
			clean_merge = 0;
			output(o, 1, "CONFLICT (%s): There is a directory with name %s in %s. "
			       "Adding %s as %s",
			       conf, path, other_branch, path, new_path);
			remove_file(o, 0, path, 0);
			update_file(o, 0, sha, mode, new_path);
		} else {
			output(o, 2, "Adding %s", path);
			update_file(o, 1, sha, mode, path);
