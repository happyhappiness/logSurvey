		backup = result =
			get_shallow_commits(&want_obj, depth,
					    SHALLOW, NOT_SHALLOW);
	while (result) {
		struct object *object = &result->item->object;
		if (!(object->flags & (CLIENT_SHALLOW|NOT_SHALLOW))) {
			packet_write(1, "shallow %s",
				     oid_to_hex(&object->oid));
			register_shallow(object->oid.hash);
			shallow_nr++;
		}
		result = result->next;
	}
	free_commit_list(backup);
	for (i = 0; i < shallows->nr; i++) {
		struct object *object = shallows->objects[i].item;