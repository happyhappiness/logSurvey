	}
	if (finish_command(&rls))
		return error ("pack-objects died");

	return bundle_to_stdout ? close(bundle_fd) : commit_lock_file(&lock);
}

int unbundle(struct bundle_header *header, int bundle_fd)
