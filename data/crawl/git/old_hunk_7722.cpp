	}

	if (is_null_sha1(new_sha1)) {
		if (delete_ref(name, old_sha1)) {
			error("failed to delete %s", name);
			return "failed to delete";
