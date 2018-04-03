			our_head_points_at = remote_head_points_at;
	}
	else {
		warning(_("You appear to have cloned an empty repository."));
		mapped_refs = NULL;
		our_head_points_at = NULL;
