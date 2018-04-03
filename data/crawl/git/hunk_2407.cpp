 	if (!revs->graph)
 		fputs(get_revision_mark(revs, commit), stdout);
 	if (revs->abbrev_commit && revs->abbrev)
-		fputs(find_unique_abbrev(get_object_hash(commit->object), revs->abbrev),
+		fputs(find_unique_abbrev(commit->object.oid.hash, revs->abbrev),
 		      stdout);
 	else
 		fputs(oid_to_hex(&commit->object.oid), stdout);
