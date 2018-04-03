	if (!strncmp(name, "refs/tags/", 10)) {
		fprintf(stderr, "* %s: updating with %s\n", name, note);
		show_new(type, sha1_new);
		return update_ref("updating tag", name, sha1_new, NULL);
	}

	current = lookup_commit_reference(sha1_old);
