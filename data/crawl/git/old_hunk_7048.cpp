	 * we do not do scan-streaming check on the pack file.
	 */
	nr_objects = p->num_objects;
	entries = xmalloc(nr_objects * sizeof(*entries));
	/* first sort entries by pack offset, since unpacking them is more efficient that way */
	for (i = 0; i < nr_objects; i++) {
		entries[i].sha1 = nth_packed_object_sha1(p, i);
		if (!entries[i].sha1)
			die("internal error pack-check nth-packed-object");
		entries[i].offset = nth_packed_object_offset(p, i);
	}
	qsort(entries, nr_objects, sizeof(*entries), compare_entries);

