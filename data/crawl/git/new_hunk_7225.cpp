		int deleted = 0;

		if (rev->loginfo && !rev->no_commit_id)
			show_log(rev);
		dump_quoted_path(dense ? "diff --cc " : "diff --combined ",
				 "", elem->path, c_meta, c_reset);
		printf("%sindex ", c_meta);
