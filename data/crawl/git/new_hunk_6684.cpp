
	read_directory(&dir, ".", "", 0, NULL);
	for(i = 0; i < dir.nr; i++) {
		struct dir_entry *ent = dir.entries[i];
		if (!cache_name_is_other(ent->name, ent->len))
			continue;
		if (!shown_header) {
			s->workdir_untracked = 1;
			wt_status_print_header(s, "Untracked files",