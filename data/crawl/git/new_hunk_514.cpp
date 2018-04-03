
	if (oid_array_lookup(points_at, oid) >= 0)
		return oid;
	obj = parse_object(oid);
	if (!obj)
		die(_("malformed object at '%s'"), refname);
	if (obj->type == OBJ_TAG)
