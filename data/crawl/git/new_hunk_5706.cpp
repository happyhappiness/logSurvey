		mapped_refs = write_remote_refs(refs, refspec, reflog_msg.buf);

		remote_head = find_ref_by_name(refs, "HEAD");
		remote_head_points_at =
			guess_remote_head(remote_head, mapped_refs, 0);

		if (option_branch) {
			struct strbuf head = STRBUF_INIT;
			strbuf_addstr(&head, src_ref_prefix);
			strbuf_addstr(&head, option_branch);
			our_head_points_at =
				find_ref_by_name(mapped_refs, head.buf);
			strbuf_release(&head);

			if (!our_head_points_at) {
				warning("Remote branch %s not found in "
					"upstream %s, using HEAD instead",
					option_branch, option_origin);
				our_head_points_at = remote_head_points_at;
			}
		}
		else
			our_head_points_at = remote_head_points_at;
	}
	else {
		warning("You appear to have cloned an empty repository.");
		our_head_points_at = NULL;
		remote_head_points_at = NULL;
		remote_head = NULL;
		option_no_checkout = 1;
		if (!option_bare)
			install_branch_config(0, "master", option_origin,
					      "refs/heads/master");
	}

	if (remote_head_points_at && !option_bare) {
		struct strbuf head_ref = STRBUF_INIT;
		strbuf_addstr(&head_ref, branch_top.buf);
		strbuf_addstr(&head_ref, "HEAD");
		create_symref(head_ref.buf,
			      remote_head_points_at->peer_ref->name,
			      reflog_msg.buf);
	}

	if (our_head_points_at) {
		/* Local default branch link */
		create_symref("HEAD", our_head_points_at->name, NULL);
		if (!option_bare) {
			const char *head = skip_prefix(our_head_points_at->name,
						       "refs/heads/");
			update_ref(reflog_msg.buf, "HEAD",
				   our_head_points_at->old_sha1,
				   NULL, 0, DIE_ON_ERR);
			install_branch_config(0, head, option_origin,
					      our_head_points_at->name);
		}
	} else if (remote_head) {
		/* Source had detached HEAD pointing somewhere. */
		if (!option_bare) {
			update_ref(reflog_msg.buf, "HEAD",
				   remote_head->old_sha1,
				   NULL, REF_NODEREF, DIE_ON_ERR);
			our_head_points_at = remote_head;
		}
	} else {
		/* Nothing to checkout out */
		if (!option_no_checkout)
