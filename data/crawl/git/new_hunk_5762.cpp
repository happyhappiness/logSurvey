	if (depth)
		return -1;

	if (!ref_map)
		return 0;

	memset(&revlist, 0, sizeof(revlist));
	revlist.argv = argv;
	revlist.git_cmd = 1;
	revlist.no_stdout = 1;
	revlist.no_stderr = 1;
	revlist.in = -1;

	err = start_command(&revlist);
	if (err) {
		error("could not run rev-list");
		return err;
	}

	/*
	 * If rev-list --stdin encounters an unknown commit, it terminates,
	 * which will cause SIGPIPE in the write loop below.
	 */
	sigchain_push(SIGPIPE, SIG_IGN);

	for (ref = ref_map; ref; ref = ref->next) {
		if (write_in_full(revlist.in, sha1_to_hex(ref->old_sha1), 40) < 0 ||
		    write_in_full(revlist.in, "\n", 1) < 0) {
			if (errno != EPIPE && errno != EINVAL)
				error("failed write to rev-list: %s", strerror(errno));
			err = -1;
			break;
		}
	}

	if (close(revlist.in)) {
		error("failed to close rev-list's stdin: %s", strerror(errno));
		err = -1;
	}

	sigchain_pop(SIGPIPE);

	return finish_command(&revlist) || err;
}

static int fetch_refs(struct transport *transport, struct ref *ref_map)
