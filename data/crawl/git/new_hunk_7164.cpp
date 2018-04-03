	}

	for (i = 0; i < dir.nr; i++)
		if (add_file_to_cache(dir.entries[i]->name, verbose)) {
			if (!ignore_add_errors)
				die("adding files failed");
			exit_status = 1;
		}

 finish:
	if (active_cache_changed) {