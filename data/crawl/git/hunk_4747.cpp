 			strbuf_release(&head);
 
 			if (!our_head_points_at) {
-				warning("Remote branch %s not found in "
-					"upstream %s, using HEAD instead",
+				warning(_("Remote branch %s not found in "
+					"upstream %s, using HEAD instead"),
 					option_branch, option_origin);
 				our_head_points_at = remote_head_points_at;
 			}
