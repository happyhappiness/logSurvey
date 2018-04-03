			die("Not a tree: %s", sha1_to_hex(sha1));
		t->delta_depth = myoe->depth;
		buf = gfi_unpack_entry(myoe, &size);
	} else {
		enum object_type type;
		buf = read_sha1_file(sha1, &type, &size);