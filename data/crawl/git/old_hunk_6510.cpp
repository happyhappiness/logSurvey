					     option_upload_pack);

		refs = transport_get_remote_refs(transport);
		transport_fetch_refs(transport, refs);
	}

	clear_extra_refs();

	mapped_refs = write_remote_refs(refs, &refspec, reflog_msg.buf);

	head_points_at = locate_head(refs, mapped_refs, &remote_head);

	if (head_points_at) {
		/* Local default branch link */
