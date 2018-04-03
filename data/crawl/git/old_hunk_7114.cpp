{
	struct object *obj = parse_object(sha1);
	const char *parent = sha1_to_hex(sha1);
	if (!obj)
		die("Unable to find commit parent %s", parent);
	if (obj->type != OBJ_COMMIT)
		die("Parent %s isn't a proper commit", parent);
	strbuf_addf(sb, "parent %s\n", parent);
}

