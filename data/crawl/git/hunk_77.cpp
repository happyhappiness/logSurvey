 		if (errno != ENOENT)
 			break;
 		if (was_alias) {
-			fprintf(stderr, "Expansion of alias '%s' failed; "
-				"'%s' is not a git command\n",
+			fprintf(stderr, _("expansion of alias '%s' failed; "
+					  "'%s' is not a git command\n"),
 				cmd, argv[0]);
 			exit(1);
 		}