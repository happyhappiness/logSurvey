	rls.git_cmd = 1;
	if (start_command(&rls))
		return error("Could not spawn pack-objects");
	for (i = 0; i < revs.pending.nr; i++) {
		struct object *object = revs.pending.objects[i].item;
		if (object->flags & UNINTERESTING)
