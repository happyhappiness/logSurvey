		return error("dst ref %s receives from more than one src.",
		      matched_dst->name);
	else {
		matched_dst->peer_ref = matched_src;
		matched_dst->force = rs->force;
	}
	return 0;
