	update_ref("updating ORIG_HEAD", "ORIG_HEAD", head_commit->object.oid.hash,
		   NULL, 0, UPDATE_REFS_DIE_ON_ERR);

	if (remoteheads && !common)
		; /* No common ancestors found. We need a real merge. */
	else if (!remoteheads ||
		 (!remoteheads->next && !common->next &&
		  common->item == remoteheads->item)) {
		/*
