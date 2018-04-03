		handle_cache(path, sha1, rerere_path(id, "thisimage"));
		if (read_mmfile(&cur, rerere_path(id, "thisimage"))) {
			free(cur.ptr);
			return error("Failed to update conflicted state in '%s'",
				     path);
		}
		cleanly_resolved = !try_merge(id, path, &cur, &result);
		free(result.ptr);