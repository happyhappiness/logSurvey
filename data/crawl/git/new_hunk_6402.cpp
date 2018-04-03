
		mapped_refs = write_remote_refs(refs, refspec, reflog_msg.buf);

		remote_head = find_ref_by_name(refs, "HEAD");
		head_points_at = guess_remote_head(remote_head, mapped_refs, 0);
	}
	else {
		warning("You appear to have cloned an empty repository.");
