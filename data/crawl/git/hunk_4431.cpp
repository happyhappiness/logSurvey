 			     git_notes_remove_usage, 0);
 
 	if (1 < argc) {
-		error("too many parameters");
+		error(_("too many parameters"));
 		usage_with_options(git_notes_remove_usage, options);
 	}
 
 	object_ref = argc ? argv[0] : "HEAD";
 
 	if (get_sha1(object_ref, object))
-		die("Failed to resolve '%s' as a valid ref.", object_ref);
+		die(_("Failed to resolve '%s' as a valid ref."), object_ref);
 
 	t = init_notes_check("remove");
 
 	retval = remove_note(t, object);
 	if (retval)
-		fprintf(stderr, "Object %s has no note\n", sha1_to_hex(object));
+		fprintf(stderr, _("Object %s has no note\n"), sha1_to_hex(object));
 	else {
-		fprintf(stderr, "Removing note for object %s\n",
+		fprintf(stderr, _("Removing note for object %s\n"),
 			sha1_to_hex(object));
 
 		commit_notes(t, "Notes removed by 'git notes remove'");
