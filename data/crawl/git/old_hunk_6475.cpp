					putchar('>');
			}
		}
		fputs(diff_unique_abbrev(commit->object.sha1, abbrev_commit),
		      stdout);
		if (opt->print_parents)
			show_parents(commit, abbrev_commit);
		if (parent)
			printf(" (from %s)",
			       diff_unique_abbrev(parent->object.sha1,
						  abbrev_commit));
		show_decorations(opt, commit);
		printf("%s", diff_get_color_opt(&opt->diffopt, DIFF_RESET));
