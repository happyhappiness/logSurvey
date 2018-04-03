static void report_missing(const struct object *obj)
{
	fprintf(stderr, "Cannot obtain needed %s %s\n",
		obj->type ? type_name(obj->type): "object",
		oid_to_hex(&obj->oid));
	if (!is_null_oid(&current_commit_oid))
		fprintf(stderr, "while processing commit %s.\n",
