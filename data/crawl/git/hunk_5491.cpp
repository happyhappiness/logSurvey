 				revs->no_walk = 0;
 				continue;
 			}
+			if (!strcmp(arg, "--stdin")) {
+				if (revs->disable_stdin) {
+					argv[left++] = arg;
+					continue;
+				}
+				if (read_from_stdin++)
+					die("--stdin given twice?");
+				read_revisions_from_stdin(revs);
+				continue;
+			}
 
 			opts = handle_revision_opt(revs, argc - i, argv + i, &left, argv);
 			if (opts > 0) {
