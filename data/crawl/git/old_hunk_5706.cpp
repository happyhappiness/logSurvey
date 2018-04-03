		mapped_refs = write_remote_refs(refs, refspec, reflog_msg.buf);

		remote_head = find_ref_by_name(refs, "HEAD");
		head_points_at = guess_remote_head(remote_head, mapped_refs, 0);
	}
	else {
		warning("You appear to have cloned an empty repository.");
		head_points_at = NULL;
		remote_head = NULL;
		option_no_checkout = 1;
		if (!option_bare)
			install_branch_config(0, "master", option_origin,
					      "refs/heads/master");
	}

	if (head_points_at) {
		/* Local default branch link */
		create_symref("HEAD", head_points_at->name, NULL);

		if (!option_bare) {
			struct strbuf head_ref = STRBUF_INIT;
			const char *head = head_points_at->name;

			if (!prefixcmp(head, "refs/heads/"))
				head += 11;

			/* Set up the initial local branch */

			/* Local branch initial value */
			update_ref(reflog_msg.buf, "HEAD",
				   head_points_at->old_sha1,
				   NULL, 0, DIE_ON_ERR);

			strbuf_addstr(&head_ref, branch_top.buf);
			strbuf_addstr(&head_ref, "HEAD");

			/* Remote branch link */
			create_symref(head_ref.buf,
				      head_points_at->peer_ref->name,
				      reflog_msg.buf);

			install_branch_config(0, head, option_origin,
					      head_points_at->name);
		}
	} else if (remote_head) {
		/* Source had detached HEAD pointing somewhere. */
		if (!option_bare)
			update_ref(reflog_msg.buf, "HEAD",
				   remote_head->old_sha1,
				   NULL, REF_NODEREF, DIE_ON_ERR);
	} else {
		/* Nothing to checkout out */
		if (!option_no_checkout)
