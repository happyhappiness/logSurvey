		rollback_lock_file(&packlock);
		return 0;
	}
	write_or_die(fd, PACKED_REFS_HEADER, strlen(PACKED_REFS_HEADER));
	do_for_each_entry_in_dir(packed, 0, repack_ref_fn, &fd);
	return commit_lock_file(&packlock);
}
