
	/* Look up all the requirements, warn about missing objects.. */
	max = get_max_object_index();
	for (i = 0; i < max; i++) {
		struct object *obj = get_indexed_object(i);

