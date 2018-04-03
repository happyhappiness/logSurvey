	 * additional safety measure to check for it.
	 */
	if (!have_message &&
	    is_old_style_invocation(argc, argv, get_object_hash(head_commit->object))) {
		warning("old-style 'git merge <msg> HEAD <commit>' is deprecated.");
		strbuf_addstr(&merge_msg, argv[0]);
		head_arg = argv[1];
