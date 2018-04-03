	for (i = 0; i < revs.pending.nr; i++) {
		struct object *object = revs.pending.objects[i].item;
		if (object->flags & UNINTERESTING)
			write_or_die(rls.in, "^", 1);
		write_or_die(rls.in, sha1_to_hex(object->sha1), 40);
		write_or_die(rls.in, "\n", 1);
	}
	if (finish_command(&rls))
		return error ("pack-objects died");
