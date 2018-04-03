		else
			new_sha1 = ref->peer_ref->new_sha1;


		ref->deletion = is_null_sha1(new_sha1);
		if (ref->deletion && !allow_deleting_refs) {
			ref->status = REF_STATUS_REJECT_NODELETE;
			continue;
		}
		if (!ref->deletion &&
		    !hashcmp(ref->old_sha1, new_sha1)) {
			ref->status = REF_STATUS_UPTODATE;
			continue;
		}

