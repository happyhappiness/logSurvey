 	}
 	if (one && two)
 		builtin_diff(name, other ? other : name,
-			     one, two, xfrm_msg, o, complete_rewrite);
+			     one, two, xfrm_msg, must_show_header,
+			     o, complete_rewrite);
 	else
 		fprintf(o->file, "* Unmerged path %s\n", name);
 }
