	if (!dest)
		usage(fetch_pack_usage);

	ref = fetch_pack(&args, dest, nr_heads, heads, NULL);
	ret = !ref;

	while (ref) {
		printf("%s %s\n",
		       sha1_to_hex(ref->old_sha1), ref->name);
