			our_head_points_at = remote_head_points_at;
	}
	else {
		warning("You appear to have cloned an empty repository.");
		our_head_points_at = NULL;
		remote_head_points_at = NULL;
		remote_head = NULL;
