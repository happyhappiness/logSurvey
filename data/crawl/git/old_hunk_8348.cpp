			     &result_size);
	free(delta_data);
	if (!result)
		bad_object(delta_obj->offset, "failed to apply delta");
	sha1_object(result, result_size, type, delta_obj->sha1);
	nr_resolved_deltas++;

	hashcpy(delta_base.sha1, delta_obj->sha1);
	if (!find_delta_children(&delta_base, &first, &last)) {
		for (j = first; j <= last; j++) {
			struct object_entry *child = objects + deltas[j].obj_no;
