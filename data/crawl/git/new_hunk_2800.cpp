			copts.padding = 2;
			run_column_filter(colopts, &copts);
		}
		filter.name_patterns = argv;
		ret = list_tags(&filter, sorting);
		if (column_active(colopts))
			stop_column_filter();
		return ret;
