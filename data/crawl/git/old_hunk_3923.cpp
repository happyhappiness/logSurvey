	struct object *o = lookup_unknown_object(sha1);
	if (!o)
		die("git upload-pack: cannot find object %s:", sha1_to_hex(sha1));
	if (!(o->flags & OUR_REF)) {
		o->flags |= OUR_REF;
		nr_our_refs++;
	}
	return 0;
}
