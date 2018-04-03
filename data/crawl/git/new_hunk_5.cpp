{
	char *tmpfile = git_pathdup("REPLACE_EDITOBJ");
	enum object_type type;
	struct object_id old_oid, new_oid, prev;
	struct strbuf ref = STRBUF_INIT;

	if (get_oid(object_ref, &old_oid) < 0)
		die("Not a valid object name: '%s'", object_ref);

	type = sha1_object_info(old_oid.hash, NULL);
	if (type < 0)
		die("unable to get object type for %s", oid_to_hex(&old_oid));

	check_ref_valid(&old_oid, &prev, &ref, force);
	strbuf_release(&ref);

	export_object(&old_oid, type, raw, tmpfile);
	if (launch_editor(tmpfile, NULL, NULL) < 0)
		die("editing object file failed");
	import_object(&new_oid, type, raw, tmpfile);

	free(tmpfile);

	if (!oidcmp(&old_oid, &new_oid))
		return error("new object is the same as the old one: '%s'", oid_to_hex(&old_oid));

	return replace_object_oid(object_ref, &old_oid, "replacement", &new_oid, force);
}

static void replace_parents(struct strbuf *buf, int argc, const char **argv)
