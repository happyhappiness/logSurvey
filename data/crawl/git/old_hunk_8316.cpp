	 * we do not do scan-streaming check on the pack file.
	 */
	nr_objects = p->num_objects;
	for (i = 0, err = 0; i < nr_objects; i++) {
		const unsigned char *sha1;
		void *data;
		enum object_type type;
		unsigned long size;
		off_t offset;

		sha1 = nth_packed_object_sha1(p, i);
		if (!sha1)
			die("internal error pack-check nth-packed-object");
		offset = find_pack_entry_one(sha1, p);
		if (!offset)
			die("internal error pack-check find-pack-entry-one");
		data = unpack_entry(p, offset, &type, &size);
		if (!data) {
			err = error("cannot unpack %s from %s",
				    sha1_to_hex(sha1), p->pack_name);
			continue;
		}
		if (check_sha1_signature(sha1, data, size, typename(type))) {
			err = error("packed %s from %s is corrupt",
				    sha1_to_hex(sha1), p->pack_name);
			free(data);
			continue;
		}
		free(data);
	}

	return err;
}