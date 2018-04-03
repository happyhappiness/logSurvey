 			 !strcmp(argv[i], "-s")) {
 			const char *committer;
 			const char *endpos;
-			committer = git_committer_info(1);
+			committer = git_committer_info(IDENT_ERROR_ON_NO_NAME);
 			endpos = strchr(committer, '>');
 			if (!endpos)
 				die("bogos committer info %s\n", committer);
