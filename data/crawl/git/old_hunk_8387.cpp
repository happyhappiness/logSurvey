		stop_progress(&progress_state);
	if (written != nr_result)
		die("wrote %u objects while expecting %u", written, nr_result);
	for (j = 0; i < nr_objects; i++) {
		struct object_entry *e = objects + i;
		j += !e->offset && !e->preferred_base;
