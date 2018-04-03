
		if (opt->output_format & DIFF_FORMAT_PATCH) {
			if (needsep)
				putchar(opt->line_termination);
			for (p = paths; p; p = p->next) {
				if (p->len)
					show_patch_diff(p, num_parent, dense,