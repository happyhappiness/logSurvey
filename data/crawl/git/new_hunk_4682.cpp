
	if (!ref_lock) {
		rollback_index_files();
		die(_("cannot lock HEAD ref"));
	}
	if (write_ref_sha1(ref_lock, commit_sha1, sb.buf) < 0) {
		rollback_index_files();
		die(_("cannot update HEAD ref"));
	}

	unlink(git_path("MERGE_HEAD"));