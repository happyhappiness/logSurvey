 	if (get_sha1(object_ref, object))
 		die(_("Failed to resolve '%s' as a valid ref."), object_ref);
 
-	t = init_notes_check("show");
+	t = init_notes_check("show", 0);
 	note = get_note(t, object);
 
 	if (!note)
