 	for_each_note(t, 0, prune_notes_helper, &l);
 
 	while (l) {
-		remove_note(t, l->sha1);
+		if (flags & NOTES_PRUNE_VERBOSE)
+			printf("%s\n", sha1_to_hex(l->sha1));
+		if (!(flags & NOTES_PRUNE_DRYRUN))
+			remove_note(t, l->sha1);
 		l = l->next;
 	}
 }
