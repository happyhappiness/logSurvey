		show_log(rev);

	if (opt->output_format & DIFF_FORMAT_RAW) {
		offset = strlen(COLONS) - num_parent;
		if (offset < 0)
			offset = 0;
		prefix = COLONS + offset;

		/* Show the modes */
		for (i = 0; i < num_parent; i++) {
			printf("%s%06o", prefix, p->parent[i].mode);
			prefix = " ";
		}
		printf("%s%06o", prefix, p->mode);

		/* Show sha1's */
		for (i = 0; i < num_parent; i++)