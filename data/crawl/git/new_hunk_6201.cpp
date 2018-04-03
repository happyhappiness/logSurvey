		}
	}

	conn = git_connect(fd, dest, receivepack, args.verbose ? CONNECT_VERBOSE : 0);

	memset(&extra_have, 0, sizeof(extra_have));

	get_remote_heads(fd[0], &remote_refs, 0, NULL, REF_NORMAL,
			 &extra_have);

	verify_remote_names(nr_refspecs, refspecs);

	local_refs = get_local_heads();

	flags = MATCH_REFS_NONE;

	if (send_all)
		flags |= MATCH_REFS_ALL;
	if (args.send_mirror)
		flags |= MATCH_REFS_MIRROR;

	/* match them up */
	remote_tail = &remote_refs;
	while (*remote_tail)
		remote_tail = &((*remote_tail)->next);
	if (match_refs(local_refs, remote_refs, &remote_tail,
		       nr_refspecs, refspecs, flags)) {
		return -1;
	}

	ret = send_pack(&args, fd, conn, remote_refs, &extra_have);

	close(fd[1]);
	close(fd[0]);

	ret |= finish_connect(conn);

	print_push_status(dest, remote_refs);

	if (!args.dry_run && remote) {
		struct ref *ref;
		for (ref = remote_refs; ref; ref = ref->next)
			update_tracking_ref(remote, ref);
	}

	if (!ret && !refs_pushed(remote_refs))
		fprintf(stderr, "Everything up-to-date\n");

	return ret;
}
