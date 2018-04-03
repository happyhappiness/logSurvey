		offset = write_pack_header(f, nr_remaining);
		if (!offset)
			die_errno("unable to write pack header");
		nr_written = 0;
		for (; i < to_pack.nr_objects; i++) {
			struct object_entry *e = write_order[i];
