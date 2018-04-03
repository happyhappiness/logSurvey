		" include-tag multi_ack_detailed";
	struct object *o = lookup_unknown_object(sha1);
	const char *refname_nons = strip_namespace(refname);

	if (o->type == OBJ_NONE) {
		o->type = sha1_object_info(sha1, NULL);
		if (o->type < 0)
		    die("git upload-pack: cannot find object %s:", sha1_to_hex(sha1));
	}

	if (capabilities)
		packet_write(1, "%s %s%c%s%s agent=%s\n",
