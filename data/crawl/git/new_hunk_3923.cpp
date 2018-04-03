	struct object *o = lookup_unknown_object(sha1);
	if (!o)
		die("git upload-pack: cannot find object %s:", sha1_to_hex(sha1));
	o->flags |= OUR_REF;
	return 0;
}
