	} else {
		const char *name = refspec->src[0] ? refspec->src : "HEAD";

		ref_map = get_remote_ref(remote_refs, name);
		if (!missing_ok && !ref_map)
			die("Couldn't find remote ref %s", name);
		if (ref_map) {
