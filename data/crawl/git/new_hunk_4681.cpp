		stripspace(&sb, cleanup_mode == CLEANUP_ALL);
	if (message_is_empty(&sb) && !allow_empty_message) {
		rollback_index_files();
		fprintf(stderr, _("Aborting commit due to empty commit message.\n"));
		exit(1);
	}

	if (commit_tree(sb.buf, active_cache_tree->sha1, parents, commit_sha1,
			author_ident.buf)) {
		rollback_index_files();
		die(_("failed to write commit object"));
	}
	strbuf_release(&author_ident);

