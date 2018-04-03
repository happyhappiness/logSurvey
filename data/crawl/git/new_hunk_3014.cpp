			handle_skipped_merge_base(mb);
		} else {
			printf("Bisecting: a merge base must be tested\n");
			exit(bisect_checkout(mb, no_checkout));
		}
	}

