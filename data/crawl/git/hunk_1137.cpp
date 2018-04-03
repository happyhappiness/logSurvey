 	 */
 
 	if (get_sha1("NOTES_MERGE_PARTIAL", sha1))
-		die(_("Failed to read ref NOTES_MERGE_PARTIAL"));
+		die(_("failed to read ref NOTES_MERGE_PARTIAL"));
 	else if (!(partial = lookup_commit_reference(sha1)))
-		die(_("Could not find commit from NOTES_MERGE_PARTIAL."));
+		die(_("could not find commit from NOTES_MERGE_PARTIAL."));
 	else if (parse_commit(partial))
-		die(_("Could not parse commit from NOTES_MERGE_PARTIAL."));
+		die(_("could not parse commit from NOTES_MERGE_PARTIAL."));
 
 	if (partial->parents)
 		hashcpy(parent_sha1, partial->parents->item->object.oid.hash);
