 
 	code = git_merge_trees(o->call_depth, common, head, merge);
 
-	if (code != 0)
-		die("merging of trees %s and %s failed",
-		    sha1_to_hex(head->object.sha1),
-		    sha1_to_hex(merge->object.sha1));
+	if (code != 0) {
+		if (show(o, 4) || o->call_depth)
+			die("merging of trees %s and %s failed",
+			    sha1_to_hex(head->object.sha1),
+			    sha1_to_hex(merge->object.sha1));
+		else
+			exit(128);
+	}
 
 	if (unmerged_cache()) {
 		struct string_list *entries, *re_head, *re_merge;