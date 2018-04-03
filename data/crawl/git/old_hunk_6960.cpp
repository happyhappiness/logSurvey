			sha = b_sha;
			conf = "directory/file";
		}
		if (path_list_has_path(&current_directory_set, path)) {
			const char *new_path = unique_path(path, add_branch);
			clean_merge = 0;
			output(1, "CONFLICT (%s): There is a directory with name %s in %s. "
