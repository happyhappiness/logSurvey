 
 	if (is_null_sha1(new_note))
 		remove_note(t, object);
-	else
-		add_note(t, object, new_note, combine_notes_overwrite);
+	else if (add_note(t, object, new_note, combine_notes_overwrite))
+		die("BUG: combine_notes_overwrite failed");
 
 	snprintf(logmsg, sizeof(logmsg), "Notes %s by 'git notes %s'",
 		 is_null_sha1(new_note) ? "removed" : "added", argv[0]);
