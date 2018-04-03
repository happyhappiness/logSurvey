	if (prepare_revision_walk(&revs))
		die("revision walk setup failed");
	revs.diffopt.format_callback = show_filemodify;
	DIFF_OPT_SET(&revs.diffopt, RECURSIVE);
	while ((commit = get_revision(&revs))) {
		if (has_unshown_parent(commit)) {
			add_object_array(&commit->object, NULL, &commits);
		}
		else {
			handle_commit(commit, &revs);
			handle_tail(&commits, &revs);
		}
	}

