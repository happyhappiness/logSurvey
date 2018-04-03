	 */
	if (!have_message &&
	    is_old_style_invocation(argc, argv, head_commit->object.sha1)) {
		warning("old-style 'git merge <msg> HEAD <commit>' is deprecated.");
		strbuf_addstr(&merge_msg, argv[0]);
		head_arg = argv[1];
		argv += 2;
