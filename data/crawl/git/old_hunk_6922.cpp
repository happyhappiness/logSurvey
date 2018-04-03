		if (mode == WORKING_DIRECTORY)
			continue;

		assert(cache_name_pos(src, strlen(src)) >= 0);

		string_list_insert(src, &deleted);
		/* destination can be a directory with 1 file inside */
		if (string_list_has_string(&overwritten, dst))
			string_list_insert(dst, &changed);
		else
			string_list_insert(dst, &added);
	}

	if (show_only) {
		show_list("Changed  : ", &changed);
		show_list("Adding   : ", &added);
		show_list("Deleting : ", &deleted);
	} else {
		for (i = 0; i < changed.nr; i++) {
			const char *path = changed.items[i].string;
			int j = cache_name_pos(path, strlen(path));
			struct cache_entry *ce = active_cache[j];

			if (j < 0)
				die ("Huh? Cache entry for %s unknown?", path);
			refresh_cache_entry(ce, 0);
		}

		for (i = 0; i < added.nr; i++) {
			const char *path = added.items[i].string;
			if (add_file_to_cache(path, verbose ? ADD_CACHE_VERBOSE : 0))
				die("updating index entries failed");
		}

		for (i = 0; i < deleted.nr; i++)
			remove_file_from_cache(deleted.items[i].string);

		if (active_cache_changed) {
			if (write_cache(newfd, active_cache, active_nr) ||
			    commit_locked_index(&lock_file))
				die("Unable to write new index file");
		}
	}

	return 0;
