 	if (!starts_with(ref, "refs/notes/"))
 		/* TRANSLATORS: the first %s will be replaced by a
 		   git notes command: 'add', 'merge', 'remove', etc.*/
-		die(_("Refusing to %s notes in %s (outside of refs/notes/)"),
+		die(_("refusing to %s notes in %s (outside of refs/notes/)"),
 		    subcommand, ref);
 	return t;
 }
