	}
	ref_cpy = do_fetch_pack(args, fd, ref, sought, nr_sought, pack_lockfile);

	if (args->depth > 0) {
		static struct lock_file lock;
		struct cache_time mtime;
		struct strbuf sb = STRBUF_INIT;
		char *shallow = git_path("shallow");
		int fd;

		mtime.sec = st.st_mtime;
		mtime.nsec = ST_MTIME_NSEC(st);
		if (stat(shallow, &st)) {
			if (mtime.sec)
				die("shallow file was removed during fetch");
		} else if (st.st_mtime != mtime.sec
#ifdef USE_NSEC
				|| ST_MTIME_NSEC(st) != mtime.nsec
#endif
			  )
			die("shallow file was changed during fetch");

		fd = hold_lock_file_for_update(&lock, shallow,
					       LOCK_DIE_ON_ERROR);
		if (!write_shallow_commits(&sb, 0)
		 || write_in_full(fd, sb.buf, sb.len) != sb.len) {
			unlink_or_warn(shallow);
			rollback_lock_file(&lock);
		} else {
			commit_lock_file(&lock);
		}
		strbuf_release(&sb);
	}

	reprepare_packed_git();
