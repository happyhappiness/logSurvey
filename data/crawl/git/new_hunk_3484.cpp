			our_head_points_at = remote_head_points_at;
	}
	else {
		if (option_branch)
			die(_("Remote branch %s not found in upstream %s"),
					option_branch, option_origin);

		warning(_("You appear to have cloned an empty repository."));
		mapped_refs = NULL;
		our_head_points_at = NULL;
