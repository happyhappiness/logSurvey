
		if (!opt->graph)
			put_revision_mark(opt, commit);
		fputs(find_unique_abbrev(get_object_hash(commit->object), abbrev_commit),
		      stdout);
		if (opt->print_parents)
			show_parents(commit, abbrev_commit);
		if (opt->children.name)
			show_children(opt, commit, abbrev_commit);
		if (parent)
			printf(" (from %s)",
			       find_unique_abbrev(get_object_hash(parent->object),
						  abbrev_commit));
		fputs(diff_get_color_opt(&opt->diffopt, DIFF_RESET), stdout);
		show_decorations(opt, commit);
