 		if (opt->commit_format != CMIT_FMT_ONELINE)
 			fputs("commit ", stdout);
 
-		if (!opt->graph) {
-			if (commit->object.flags & BOUNDARY)
-				putchar('-');
-			else if (commit->object.flags & UNINTERESTING)
-				putchar('^');
-			else if (opt->left_right) {
-				if (commit->object.flags & SYMMETRIC_LEFT)
-					putchar('<');
-				else
-					putchar('>');
-			}
-		}
+		if (!opt->graph)
+			fputs(get_revision_mark(opt, commit), stdout);
 		fputs(find_unique_abbrev(commit->object.sha1, abbrev_commit),
 		      stdout);
 		if (opt->print_parents)
