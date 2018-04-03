			f = create_tmp_packfile(&pack_tmp_name);

		offset = write_pack_header(f, nr_remaining);
		nr_written = 0;
		for (; i < nr_objects; i++) {
			struct object_entry *e = write_order[i];
