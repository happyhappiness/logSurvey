
	/* Nuke the recorded resolution for the conflict */
	id = new_rerere_id(sha1);

	for (id->variant = 0;
	     id->variant < id->collection->status_nr;
	     id->variant++) {
		mmfile_t cur = { NULL, 0 };
		mmbuffer_t result = {NULL, 0};
		int cleanly_resolved;

		if (!has_rerere_resolution(id))
			continue;

		handle_cache(path, sha1, rerere_path(id, "thisimage"));
		if (read_mmfile(&cur, rerere_path(id, "thisimage"))) {
			free(cur.ptr);
			return error("Failed to update conflicted state in '%s'",
				     path);
		}
		cleanly_resolved = !try_merge(id, path, &cur, &result);
		free(result.ptr);
		free(cur.ptr);
		if (cleanly_resolved)
			break;
	}

	if (id->collection->status_nr <= id->variant)
		return error("no remembered resolution for '%s'", path);

	filename = rerere_path(id, "postimage");
	if (unlink(filename))
		return (errno == ENOENT
