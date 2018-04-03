
	/* Nuke the recorded resolution for the conflict */
	id = new_rerere_id(sha1);
	id->variant = 0; /* for now */
	filename = rerere_path(id, "postimage");
	if (unlink(filename))
		return (errno == ENOENT
