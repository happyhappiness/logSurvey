		second_token = lookup_commit_reference_gently(second_sha1, 0);
		if (!second_token)
			die(_("'%s' is not a commit"), argv[1]);
		if (hashcmp(get_object_hash(second_token->object), head))
			return NULL;
	}
	return second_token;
