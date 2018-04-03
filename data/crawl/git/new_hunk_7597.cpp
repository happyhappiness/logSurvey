"You may want to amend it after fixing the message, or set the config\n"
"variable i18n.commitencoding to the encoding your project uses.\n";

static void add_parent(struct strbuf *sb, const unsigned char *sha1)
{
	struct object *obj = parse_object(sha1);
	const char *parent = sha1_to_hex(sha1);
	if (!obj)
		die("Unable to find commit parent %s", parent);
	if (obj->type != OBJ_COMMIT)
		die("Parent %s isn't a proper commit", parent);
	strbuf_addf(sb, "parent %s\n", parent);
}

int cmd_commit(int argc, const char **argv, const char *prefix)
{
	int header_len;
