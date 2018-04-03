 			bisect_show_vars = 1;
 			continue;
 		}
-		if (!strcmp(arg, "--stdin")) {
-			if (read_from_stdin++)
-				die("--stdin given twice?");
-			read_revisions_from_stdin(&revs);
-			continue;
-		}
 		usage(rev_list_usage);
 
 	}
