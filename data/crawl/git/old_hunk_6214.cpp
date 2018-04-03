		 */
		add = added;
		del = deleted;
		total = add + del;
		adds += add;
		dels += del;

		if (width <= max_change) {
			add = scale_linear(add, width, max_change);
			del = scale_linear(del, width, max_change);
			total = add + del;
		}
		show_name(options->file, prefix, name, len, reset, set);
		fprintf(options->file, "%5d%s", added + deleted,
