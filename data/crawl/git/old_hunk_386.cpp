	} else if (!strcmp(arg, "--author-date-order")) {
		revs->sort_order = REV_SORT_BY_AUTHOR_DATE;
		revs->topo_order = 1;
	} else if (starts_with(arg, "--early-output")) {
		int count = 100;
		switch (arg[14]) {
		case '=':
			count = atoi(arg+15);
			/* Fallthrough */
		case 0:
			revs->topo_order = 1;
		       revs->early_output = count;
		}
	} else if (!strcmp(arg, "--parents")) {
		revs->rewrite_parents = 1;
		revs->print_parents = 1;