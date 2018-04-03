	return 0;
}

static int fsck_handle_reflog(const char *logname, const struct object_id *oid,
			      int flag, void *cb_data)
{
	for_each_reflog_ent(logname, fsck_handle_reflog_ent, NULL);
	return 0;
}

static int fsck_handle_ref(const char *refname, const struct object_id *oid,
			   int flag, void *cb_data)
{
	struct object *obj;

	obj = parse_object(oid->hash);
	if (!obj) {
		error("%s: invalid sha1 pointer %s", refname, oid_to_hex(oid));
		errors_found |= ERROR_REACHABLE;
		/* We'll continue with the rest despite the error.. */
		return 0;
