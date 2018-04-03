		if (!mode) {
			/* mode == 0 means there is no such path -- remove */
			if (remove_file_from_cache(path_name))
				die("git update-index: unable to remove %s",
				    ptr);
		}
		else {
