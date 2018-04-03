 	revs->pending.objects = NULL;
 
 	if (haves) {
+		revs->ignore_missing_links = 1;
 		haves_bitmap = find_objects(revs, haves, NULL);
 		reset_revision_walk();
+		revs->ignore_missing_links = 0;
 
 		if (haves_bitmap == NULL)
 			die("BUG: failed to perform bitmap walk");
