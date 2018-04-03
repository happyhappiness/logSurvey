		 */
		if (options->close_file)
			fclose(options->file);
		options->file = xfopen("/dev/null", "w");
		options->close_file = 1;
		for (i = 0; i < q->nr; i++) {
			struct diff_filepair *p = q->queue[i];
