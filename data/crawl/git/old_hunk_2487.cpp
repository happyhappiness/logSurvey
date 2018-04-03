	}
	if (!author) {
		warning(_("Missing author: %s"),
		    sha1_to_hex(commit->object.sha1));
		return;
	}
	if (log->user_format) {
