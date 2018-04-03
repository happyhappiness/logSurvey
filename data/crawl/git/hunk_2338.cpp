 
 	if (!t)
 		t = &default_notes_tree;
-	if (!t->initialized || !t->ref || !*t->ref)
+	if (!t->initialized || !t->update_ref || !*t->update_ref)
 		die(_("Cannot commit uninitialized/unreferenced notes tree"));
 	if (!t->dirty)
 		return; /* don't have to commit an unchanged tree */
