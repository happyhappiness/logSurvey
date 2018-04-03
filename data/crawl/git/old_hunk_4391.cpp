			fputs("commit ", stdout);

		if (!opt->graph)
			fputs(get_revision_mark(opt, commit), stdout);
		fputs(find_unique_abbrev(commit->object.sha1, abbrev_commit),
		      stdout);
		if (opt->print_parents)
