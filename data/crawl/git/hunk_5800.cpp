 		stage++;
 	}
 	if ((opts.update||opts.index_only) && !opts.merge)
-		usage(read_tree_usage);
+		die("%s is meaningless without -m, --reset, or --prefix",
+		    opts.update ? "-u" : "-i");
 	if ((opts.dir && !opts.update))
 		die("--exclude-per-directory is meaningless unless -u");
 	if (opts.merge && !opts.index_only)