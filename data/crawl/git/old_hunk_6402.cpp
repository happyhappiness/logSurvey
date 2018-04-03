
		mapped_refs = write_remote_refs(refs, refspec, reflog_msg.buf);

		head_points_at = locate_head(refs, mapped_refs, &remote_head);
	}
	else {
		warning("You appear to have cloned an empty repository.");
