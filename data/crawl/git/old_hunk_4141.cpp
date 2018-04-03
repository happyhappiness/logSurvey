		if (!allow_fast_forward)
			die(_("Non-fast-forward commit does not make sense into "
			    "an empty head"));
		remote_head = get_merge_parent(argv[0]);
		if (!remote_head)
			die(_("%s - not something we can merge"), argv[0]);
		read_empty(remote_head->object.sha1, 0);
