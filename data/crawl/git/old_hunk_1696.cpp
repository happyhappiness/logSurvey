
	if (verbose)
		fprintf(stderr, "Checking %s %s\n",
			typename(obj->type), oid_to_hex(&obj->oid));

	if (fsck_walk(obj, NULL, &fsck_obj_options))
		objerror(obj, "broken links");
