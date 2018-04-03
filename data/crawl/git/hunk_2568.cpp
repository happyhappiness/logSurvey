 	if (!revs->graph)
 		fputs(get_revision_mark(revs, commit), stdout);
 	if (revs->abbrev_commit && revs->abbrev)
-		fputs(find_unique_abbrev(commit->object.sha1, revs->abbrev),
+		fputs(find_unique_abbrev(get_object_hash(commit->object), revs->abbrev),
 		      stdout);
 	else
 		fputs(sha1_to_hex(commit->object.sha1), stdout);
