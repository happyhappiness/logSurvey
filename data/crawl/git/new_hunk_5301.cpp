
		if (get_sha1(b, sha1))
			die("Not a valid object name %s", b);
		assert_sha1_type(sha1, OBJ_COMMIT);
		new_parent(lookup_commit(sha1), &parents);
	}

