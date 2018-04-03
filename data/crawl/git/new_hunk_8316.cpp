	 * we do not do scan-streaming check on the pack file.
	 */
	nr_objects = p->num_objects;
	entries = xmalloc(nr_objects * sizeof(*entries));
	/* first sort entries by pack offset, since unpacking them is more efficient that way */
	for (i = 0; i < nr_objects; i++) {
		entries[i].sha1 = nth_packed_object_sha1(p, i);
		if (!entries[i].sha1)
			die("internal error pack-check nth-packed-object");
		entries[i].offset = find_pack_entry_one(entries[i].sha1, p);
		if (!entries[i].offset)
			die("internal error pack-check find-pack-entry-one");
	}
	qsort(entries, nr_objects, sizeof(*entries), compare_entries);

	for (i = 0, err = 0; i < nr_objects; i++) {
		void *data;
		enum object_type type;
		unsigned long size;

		data = unpack_entry(p, entries[i].offset, &type, &size);
		if (!data) {
			err = error("cannot unpack %s from %s",
				    sha1_to_hex(entries[i].sha1), p->pack_name);
			continue;
		}
		if (check_sha1_signature(entries[i].sha1, data, size, typename(type))) {
			err = error("packed %s from %s is corrupt",
				    sha1_to_hex(entries[i].sha1), p->pack_name);
			free(data);
			continue;
		}
		free(data);
	}
	free(entries);

	return err;
}