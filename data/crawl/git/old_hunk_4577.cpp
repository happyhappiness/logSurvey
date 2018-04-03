
		o = peel_to_type(argv[i], 0, NULL, OBJ_COMMIT);
		if (!o)
			die("%s - not something we can merge", argv[i]);
		commit = lookup_commit(o->sha1);
		commit->util = (void *)argv[i];
		remotes = &commit_list_insert(commit, remotes)->next;
