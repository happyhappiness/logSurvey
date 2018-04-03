	}
	if (!author) {
		warning(_("Missing author: %s"),
		    oid_to_hex(&commit->object.oid));
		return;
	}
	if (log->user_format) {
