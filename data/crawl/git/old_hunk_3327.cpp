	if (have_duplicate_entry(sha1, exclude, &index_pos))
		return 0;

	if (!want_object_in_pack(sha1, exclude, &found_pack, &found_offset))
		return 0;

	create_object_entry(sha1, type, pack_name_hash(name),
			    exclude, name && no_try_delta(name),
