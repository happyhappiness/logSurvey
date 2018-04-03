		if (rev->loginfo && !rev->no_commit_id)
			show_log(rev, opt->msg_sep);
		dump_quoted_path(dense ? "diff --cc " : "diff --combined ",
				 "", elem->path, c_meta, c_reset);
		printf("%sindex ", c_meta);
		for (i = 0; i < num_parent; i++) {
			abb = find_unique_abbrev(elem->parent[i].sha1,
