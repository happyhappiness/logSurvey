			copts.padding = 2;
			run_column_filter(colopts, &copts);
		}
		ret = list_tags(argv, lines == -1 ? 0 : lines, with_commit);
		if (column_active(colopts))
			stop_column_filter();
		return ret;
