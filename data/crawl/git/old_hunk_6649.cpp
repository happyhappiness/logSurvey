	 * insane, so we know won't exceed what we have been given.
	 */
	base = use_pack(p, w_curs, *curpos, &left);
	used = unpack_object_header_gently(base, left, &type, sizep);
	if (!used)
		die("object offset outside of pack file");
	*curpos += used;

	return type;
}