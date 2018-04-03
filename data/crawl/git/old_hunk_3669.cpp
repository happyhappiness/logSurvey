	fprintf(cb->refs_file, "%s %s\n", sha1_to_hex(entry->u.value.sha1),
		entry->name);

	o = parse_object_or_die(entry->u.value.sha1, entry->name);
	if (o->type == OBJ_TAG) {
		o = deref_tag(o, entry->name, 0);
		if (o)
			fprintf(cb->refs_file, "^%s\n",
				sha1_to_hex(o->sha1));
	}

	/* If the ref was already packed, there is no need to prune it. */
	if ((cb->flags & PACK_REFS_PRUNE) && !(entry->flag & REF_ISPACKED)) {
