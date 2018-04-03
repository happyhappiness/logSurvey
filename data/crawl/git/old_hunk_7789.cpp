	if (myoe && myoe->pack_id != MAX_PACK_ID) {
		if (myoe->type != OBJ_TREE)
			die("Not a tree: %s", sha1_to_hex(sha1));
		t->delta_depth = 0;
		buf = gfi_unpack_entry(myoe, &size);
	} else {
		enum object_type type;
