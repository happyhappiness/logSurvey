	pos = cache_name_pos(path, strlen(path));
	if (pos >= 0)
		; /* path is in the index */
	else if (!strcmp(active_cache[-1 - pos]->name, path))
		; /* path is in the index, unmerged */
	else
		die("no such path '%s' in HEAD", path);
