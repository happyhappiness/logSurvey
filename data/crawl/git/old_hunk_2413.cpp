	if (!ret) {
		enum object_type type;
		unsigned long size;
		ret = read_sha1_file(get_object_hash(commit->object), &type, &size);
		if (!ret)
			die("cannot read commit object %s",
			    oid_to_hex(&commit->object.oid));
