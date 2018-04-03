
	if (verbose)
		fprintf(stderr, "Checking %s %s\n",
			typename(obj->type), sha1_to_hex(obj->sha1));

	if (fsck_walk(obj, NULL, &fsck_obj_options))
		objerror(obj, "broken links");
