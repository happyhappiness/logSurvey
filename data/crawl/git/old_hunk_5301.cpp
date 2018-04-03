
		if (get_sha1(b, sha1))
			die("Not a valid object name %s", b);
		check_valid(sha1, OBJ_COMMIT);
		new_parent(lookup_commit(sha1), &parents);
	}

