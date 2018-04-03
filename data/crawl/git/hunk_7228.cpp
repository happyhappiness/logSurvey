 			DIFF_OPT_SET(&revs->diffopt, EXIT_WITH_STATUS);
 			break;
 		}
+	if (nongit && argc != i + 2)
+		die("git diff [--no-index] takes two paths");
+
 	if (argc != i + 2 || (!is_outside_repo(argv[i + 1], nongit, prefix) &&
 				!is_outside_repo(argv[i], nongit, prefix)))
 		return -1;
