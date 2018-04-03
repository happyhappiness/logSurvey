 
 			first = cache_name_pos(src_w_slash, len_w_slash);
 			if (first >= 0)
-				die ("Huh? %.*s is in index?",
+				die (_("Huh? %.*s is in index?"),
 						len_w_slash, src_w_slash);
 
 			first = -1 - first;
