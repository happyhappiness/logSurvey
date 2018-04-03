	if (obj->type == OBJ_COMMIT) {
		struct commit *commit = (struct commit *) obj;

		free(commit->buffer);
		commit->buffer = NULL;

		if (!commit->parents && show_root)
			printf("root %s\n", sha1_to_hex(commit->object.sha1));
