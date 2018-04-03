{
	struct object *obj = parse_object(sha1);
	const char *parent = sha1_to_hex(sha1);
	const char *cp;

	if (!obj)
		die("Unable to find commit parent %s", parent);
	if (obj->type != OBJ_COMMIT)
		die("Parent %s isn't a proper commit", parent);

	for (cp = sb->buf; cp && (cp = strstr(cp, "\nparent ")); cp += 8) {
		if (!memcmp(cp + 8, parent, 40) && cp[48] == '\n') {
			error("duplicate parent %s ignored", parent);
			return;
		}
	}
	strbuf_addf(sb, "parent %s\n", parent);
}

