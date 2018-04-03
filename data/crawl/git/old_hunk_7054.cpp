		entries[i].sha1 = nth_packed_object_sha1(p, i);
		if (!entries[i].sha1)
			die("internal error pack-check nth-packed-object");
		entries[i].offset = find_pack_entry_one(entries[i].sha1, p);
		if (!entries[i].offset)
			die("internal error pack-check find-pack-entry-one");
	}
	qsort(entries, nr_objects, sizeof(*entries), compare_entries);

