
			try_merge = 0;

			if (path_list_has_path(&current_directory_set, ren1_dst)) {
				clean_merge = 0;
				output(1, "CONFLICT (rename/directory): Renamed %s->%s in %s "
				       " directory %s added in %s",
