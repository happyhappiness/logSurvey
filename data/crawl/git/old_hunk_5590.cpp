
		if (!rc)
			fprintf(stderr, "    done\n");
		unlock_remote(ref_lock);
		check_locks();
	}
