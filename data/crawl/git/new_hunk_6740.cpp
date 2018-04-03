
	if (cleanup_mode != CLEANUP_NONE)
		stripspace(&sb, cleanup_mode == CLEANUP_ALL);
	if (message_is_empty(&sb)) {
		rollback_index_files();
		fprintf(stderr, "Aborting commit due to empty commit message.\n");
		exit(1);
	}

	if (commit_tree(sb.buf, active_cache_tree->sha1, parents, commit_sha1,
			fmt_ident(author_name, author_email, author_date,
				IDENT_ERROR_ON_NO_NAME))) {
		rollback_index_files();
		die("failed to write commit object");
	}
