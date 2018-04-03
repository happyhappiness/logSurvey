 		stop_progress(&progress_state);
 	if (written != nr_result)
 		die("wrote %u objects while expecting %u", written, nr_result);
+	/*
+	 * We have scanned through [0 ... i).  Since we have written
+	 * the correct number of objects,  the remaining [i ... nr_objects)
+	 * items must be either already written (due to out-of-order delta base)
+	 * or a preferred base.  Count those which are neither and complain if any.
+	 */
 	for (j = 0; i < nr_objects; i++) {
 		struct object_entry *e = objects + i;
 		j += !e->offset && !e->preferred_base;
