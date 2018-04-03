	if (!opt->verbose_header) {
		graph_show_commit(opt->graph);

		if (!opt->graph) {
			if (commit->object.flags & BOUNDARY)
				putchar('-');
			else if (commit->object.flags & UNINTERESTING)
				putchar('^');
			else if (opt->left_right) {
				if (commit->object.flags & SYMMETRIC_LEFT)
					putchar('<');
				else
					putchar('>');
			}
		}
		fputs(find_unique_abbrev(commit->object.sha1, abbrev_commit), stdout);
		if (opt->print_parents)
			show_parents(commit, abbrev_commit);
