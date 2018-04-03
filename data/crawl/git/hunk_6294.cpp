 		}
 		else if (!strcmp(argv[i], "--signoff") ||
 			 !strcmp(argv[i], "-s")) {
-			const char *committer;
-			const char *endpos;
-			committer = git_committer_info(IDENT_ERROR_ON_NO_NAME);
-			endpos = strchr(committer, '>');
-			if (!endpos)
-				die("bogus committer info %s", committer);
-			add_signoff = xmemdupz(committer, endpos - committer + 1);
+			do_signoff = 1;
 		}
 		else if (!strcmp(argv[i], "--attach")) {
 			rev.mime_boundary = git_version_string;
