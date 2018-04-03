					putchar('>');
			}
		}
		fputs(diff_unique_abbrev(commit->object.sha1, abbrev_commit), stdout);
		if (opt->print_parents)
			show_parents(commit, abbrev_commit);
		show_decorations(opt, commit);
