		const char *conf;

		if (a_sha) {
			add_branch = branch1;
			other_branch = branch2;
			mode = a_mode;
			sha = a_sha;
			conf = "file/directory";
		} else {
			add_branch = branch2;
			other_branch = branch1;
			mode = b_mode;
			sha = b_sha;
			conf = "directory/file";
		}
		if (string_list_has_string(&current_directory_set, path)) {
			const char *new_path = unique_path(path, add_branch);
			clean_merge = 0;
			output(1, "CONFLICT (%s): There is a directory with name %s in %s. "
			       "Adding %s as %s",
			       conf, path, other_branch, path, new_path);
			remove_file(0, path, 0);
			update_file(0, sha, mode, new_path);
		} else {
			output(2, "Adding %s", path);
			update_file(1, sha, mode, path);
		}
	} else if (a_sha && b_sha) {
		/* Case C: Added in both (check for same permissions) and */
		/* case D: Modified in both, but differently. */
		const char *reason = "content";
		struct merge_file_info mfi;
		struct diff_filespec o, a, b;

		if (!o_sha) {
			reason = "add/add";
			o_sha = (unsigned char *)null_sha1;
		}
		output(2, "Auto-merging %s", path);
		o.path = a.path = b.path = (char *)path;
		hashcpy(o.sha1, o_sha);
		o.mode = o_mode;
		hashcpy(a.sha1, a_sha);
		a.mode = a_mode;
		hashcpy(b.sha1, b_sha);
		b.mode = b_mode;

		mfi = merge_file(&o, &a, &b,
				 branch1, branch2);

		clean_merge = mfi.clean;
		if (mfi.clean)
			update_file(1, mfi.sha, mfi.mode, path);
		else if (S_ISGITLINK(mfi.mode))
			output(1, "CONFLICT (submodule): Merge conflict in %s "
			       "- needs %s", path, sha1_to_hex(b.sha1));
		else {
			output(1, "CONFLICT (%s): Merge conflict in %s",
					reason, path);

			if (index_only)
