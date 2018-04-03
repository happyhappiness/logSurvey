		return "funny refname";
	}

	switch (deny_current_branch) {
	case DENY_IGNORE:
		break;
	case DENY_WARN:
		if (!is_ref_checked_out(name))
			break;
		warning("updating the currently checked out branch; this may"
			" cause confusion,\n"
			"as the index and working tree do not reflect changes"
			" that are now in HEAD.");
		break;
	case DENY_REFUSE:
		if (!is_ref_checked_out(name))
			break;
		error("refusing to update checked out branch: %s", name);
		return "branch is currently checked out";
	}

	if (!is_null_sha1(new_sha1) && !has_sha1_file(new_sha1)) {
