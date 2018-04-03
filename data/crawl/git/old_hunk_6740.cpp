
	if (cleanup_mode != CLEANUP_NONE)
		stripspace(&sb, cleanup_mode == CLEANUP_ALL);
	if (sb.len < header_len || message_is_empty(&sb, header_len)) {
		rollback_index_files();
		fprintf(stderr, "Aborting commit due to empty commit message.\n");
		exit(1);
	}
	strbuf_addch(&sb, '\0');
	if (is_encoding_utf8(git_commit_encoding) && !is_utf8(sb.buf))
		fprintf(stderr, commit_utf8_warn);

	if (write_sha1_file(sb.buf, sb.len - 1, commit_type, commit_sha1)) {
		rollback_index_files();
		die("failed to write commit object");
	}
