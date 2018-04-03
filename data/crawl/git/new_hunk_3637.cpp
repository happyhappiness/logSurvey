	}
	ref_cpy = do_fetch_pack(args, fd, ref, sought, nr_sought, pack_lockfile);

	if (alternate_shallow_file) {
		if (*alternate_shallow_file == '\0') { /* --unshallow */
			unlink_or_warn(git_path("shallow"));
			rollback_lock_file(&shallow_lock);
		} else
			commit_lock_file(&shallow_lock);
	}

	reprepare_packed_git();
