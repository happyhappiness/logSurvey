	 */
	if (!obj->used) {
		if (show_dangling)
			printf("dangling %s %s\n", printable_type(obj),
			       describe_object(obj));
		if (write_lost_and_found) {
			char *filename = git_pathdup("lost-found/%s/%s",
