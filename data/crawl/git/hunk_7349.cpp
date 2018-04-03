 
 	n = cmit->util;
 	if (n) {
+		/*
+		 * Exact match to an existing ref.
+		 */
 		display_name(n);
+		if (longformat)
+			show_suffix(0, n->tag->tagged->sha1);
 		printf("\n");
 		return;
 	}
