		show_log(rev);

	if (opt->output_format & DIFF_FORMAT_RAW) {
		/* As many colons as there are parents */
		for (i = 0; i < num_parent; i++)
			putchar(':');

		/* Show the modes */
		for (i = 0; i < num_parent; i++)
			printf("%06o ", p->parent[i].mode);
		printf("%06o", p->mode);

		/* Show sha1's */
		for (i = 0; i < num_parent; i++)