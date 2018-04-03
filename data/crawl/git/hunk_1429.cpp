 		/*
 		 * When the merge fails, the result contains files
 		 * with conflict markers. The cleanness flag is
-		 * ignored, it was never actually used, as result of
-		 * merge_trees has always overwritten it: the committed
-		 * "conflicts" were already resolved.
+		 * ignored (unless indicating an error), it was never
+		 * actually used, as result of merge_trees has always
+		 * overwritten it: the committed "conflicts" were
+		 * already resolved.
 		 */
 		discard_cache();
 		saved_b1 = o->branch1;
 		saved_b2 = o->branch2;
 		o->branch1 = "Temporary merge branch 1";
 		o->branch2 = "Temporary merge branch 2";
-		merge_recursive(o, merged_common_ancestors, iter->item,
-				NULL, &merged_common_ancestors);
+		if (merge_recursive(o, merged_common_ancestors, iter->item,
+				    NULL, &merged_common_ancestors) < 0)
+			return -1;
 		o->branch1 = saved_b1;
 		o->branch2 = saved_b2;
 		o->call_depth--;
 
 		if (!merged_common_ancestors)
-			die(_("merge returned no commit"));
+			return err(o, _("merge returned no commit"));
 	}
 
 	discard_cache();
