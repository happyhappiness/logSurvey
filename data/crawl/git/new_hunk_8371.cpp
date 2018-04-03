	if (i != argc)
		usage(builtin_pack_refs_usage);

	return pack_refs(flags);
}