	if (msg && !*msg)
		die("Refusing to perform update with empty message.");

	if (argc < 2 || argc > 3)
		usage_with_options(git_update_ref_usage, options);
	refname = argv[0];
	value   = argv[1];
	oldval  = argv[2];

	if (get_sha1(value, sha1))
		die("%s: not a valid SHA1", value);

	if (delete) {
		if (oldval)
			usage_with_options(git_update_ref_usage, options);
		return delete_ref(refname, sha1);
	}

	hashclr(oldsha1);
	if (oldval && *oldval && get_sha1(oldval, oldsha1))
		die("%s: not a valid old SHA1", oldval);

	return update_ref(msg, refname, sha1, oldval ? oldsha1 : NULL,
			  no_deref ? REF_NODEREF : 0, DIE_ON_ERR);
}