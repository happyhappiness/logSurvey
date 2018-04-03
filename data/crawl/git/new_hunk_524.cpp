	entries[nr_objects].offset = pack_sig_ofs;
	/* first sort entries by pack offset, since unpacking them is more efficient that way */
	for (i = 0; i < nr_objects; i++) {
		entries[i].oid.hash = nth_packed_object_sha1(p, i);
		if (!entries[i].oid.hash)
			die("internal error pack-check nth-packed-object");
		entries[i].offset = nth_packed_object_offset(p, i);
		entries[i].nr = i;