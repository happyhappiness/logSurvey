		}
		if (close(msg_fd) || commit_lock_file(&msg_file) < 0)
			die ("Error wrapping up %s", defmsg);
		fprintf(stderr, "Automatic %s failed.  "
			"After resolving the conflicts,\n"
			"mark the corrected paths with 'git add <paths>' "
			"and commit the result.\n", me);
		if (action == CHERRY_PICK) {
			fprintf(stderr, "When commiting, use the option "
				"'-c %s' to retain authorship and message.\n",
				find_unique_abbrev(commit->object.sha1,
					DEFAULT_ABBREV));
		}
		exit(1);
	}
	if (close(msg_fd) || commit_lock_file(&msg_file) < 0)
