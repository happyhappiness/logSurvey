		      dst_value);
		break;
	}
	if (!matched_dst)
		return -1;
	if (matched_dst->peer_ref)
		return error("dst ref %s receives from more than one src.",
		      matched_dst->name);
	else {
		matched_dst->peer_ref = matched_src;
		matched_dst->force = rs->force;
	}
	return 0;
}

static int match_explicit_refs(struct ref *src, struct ref *dst,
