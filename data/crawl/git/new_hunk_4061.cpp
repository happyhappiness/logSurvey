		" include-tag multi_ack_detailed";
	struct object *o = lookup_unknown_object(sha1);
	const char *refname_nons = strip_namespace(refname);
	unsigned char peeled[20];

	if (capabilities)
		packet_write(1, "%s %s%c%s%s agent=%s\n",
