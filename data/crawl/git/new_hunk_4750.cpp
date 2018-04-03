
		if (write_cache(fd, active_cache, active_nr) ||
		    commit_locked_index(lock_file))
			die(_("unable to write new index file"));

		err |= run_hook(NULL, "post-checkout", sha1_to_hex(null_sha1),
				sha1_to_hex(our_head_points_at->old_sha1), "1",