	if (refs) {
		clear_extra_refs();

		mapped_refs = write_remote_refs(refs, &refspec, reflog_msg.buf);

		head_points_at = locate_head(refs, mapped_refs, &remote_head);
	}
	else {
		warning("You appear to have cloned an empty repository.");
		head_points_at = NULL;
		remote_head = NULL;
		option_no_checkout = 1;
		if (!option_bare)
			install_branch_config("master", option_origin,
					      "refs/heads/master");
	}
