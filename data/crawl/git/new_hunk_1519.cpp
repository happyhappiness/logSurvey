		if (!get_sha1(name, sha1)) {
			if (!lookup_commit_reference_gently(sha1, 1)) {
				enum object_type type = sha1_object_info(sha1, NULL);
				return error(_("%s: can't cherry-pick a %s"),
					name, typename(type));
			}
		} else
			return error(_("%s: bad revision"), name);
	}

	/*
