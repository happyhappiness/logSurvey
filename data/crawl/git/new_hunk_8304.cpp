		return -1;
	target = find_sha1_pack(sha1, packs);
	if (!target)
		return error("Couldn't find %s: not separate or in any pack",
			     sha1_to_hex(sha1));
	if (get_verbosely) {
		fprintf(stderr, "Getting pack %s\n",
			sha1_to_hex(target->sha1));
		fprintf(stderr, " which contains %s\n",
			sha1_to_hex(sha1));
	}
	sprintf(filename, "%s/objects/pack/pack-%s.pack",
		path, sha1_to_hex(target->sha1));
	copy_file(filename, sha1_pack_name(target->sha1),
		  sha1_to_hex(target->sha1), 1);
	sprintf(filename, "%s/objects/pack/pack-%s.idx",
		path, sha1_to_hex(target->sha1));
	copy_file(filename, sha1_pack_index_name(target->sha1),
		  sha1_to_hex(target->sha1), 1);
