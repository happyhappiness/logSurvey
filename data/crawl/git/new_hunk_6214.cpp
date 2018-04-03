		 */
		add = added;
		del = deleted;
		adds += add;
		dels += del;

		if (width <= max_change) {
			add = scale_linear(add, width, max_change);
			del = scale_linear(del, width, max_change);
		}
		show_name(options->file, prefix, name, len, reset, set);
		fprintf(options->file, "%5d%s", added + deleted,
