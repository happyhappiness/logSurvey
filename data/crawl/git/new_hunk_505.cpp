
	if (is_null_oid(new_oid)) {
		struct strbuf err = STRBUF_INIT;
		if (!parse_object(old_oid)) {
			old_oid = NULL;
			if (ref_exists(name)) {
				rp_warning("Allowing deletion of corrupt ref.");
