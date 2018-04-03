	struct object *o = parse_object(sha1);

	if (!o)
		die("git-upload-pack: cannot find object %s:", sha1_to_hex(sha1));

	if (capabilities)
		packet_write(1, "%s %s%c%s\n", sha1_to_hex(sha1), refname,