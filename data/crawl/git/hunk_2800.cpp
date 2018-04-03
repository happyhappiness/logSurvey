 			copts.padding = 2;
 			run_column_filter(colopts, &copts);
 		}
-		if (filter.lines != -1 && tag_sort)
-			die(_("--sort and -n are incompatible"));
 		filter.name_patterns = argv;
-		ret = list_tags(&filter, tag_sort);
+		ret = list_tags(&filter, sorting);
 		if (column_active(colopts))
 			stop_column_filter();
 		return ret;
