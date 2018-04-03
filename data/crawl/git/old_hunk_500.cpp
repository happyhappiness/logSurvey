{
	struct object *obj;

	obj = parse_object(oid->hash);
	if (!obj) {
		error("%s: invalid sha1 pointer %s", refname, oid_to_hex(oid));
		errors_found |= ERROR_REACHABLE;
