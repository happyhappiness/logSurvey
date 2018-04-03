		backup = result =
			get_shallow_commits(&want_obj, depth,
					    SHALLOW, NOT_SHALLOW);
	send_shallow(result);
	free_commit_list(backup);
	for (i = 0; i < shallows->nr; i++) {
		struct object *object = shallows->objects[i].item;