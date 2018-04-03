 	if (info->header_prefix)
 		fputs(info->header_prefix, stdout);
 
-	if (!revs->graph) {
-		if (commit->object.flags & BOUNDARY)
-			putchar('-');
-		else if (commit->object.flags & UNINTERESTING)
-			putchar('^');
-		else if (revs->left_right) {
-			if (commit->object.flags & SYMMETRIC_LEFT)
-				putchar('<');
-			else
-				putchar('>');
-		}
-	}
+	if (!revs->graph)
+		fputs(get_revision_mark(revs, commit), stdout);
 	if (revs->abbrev_commit && revs->abbrev)
 		fputs(find_unique_abbrev(commit->object.sha1, revs->abbrev),
 		      stdout);
