 				return error("%s: does not match index",
 					     old_name);
 			if (cached)
-				st_mode = ntohl(ce->ce_mode);
+				st_mode = ce->ce_mode;
 		} else if (stat_ret < 0)
 			return error("%s: %s", old_name, strerror(errno));
 
 		if (!cached)
-			st_mode = ntohl(ce_mode_from_stat(ce, st.st_mode));
+			st_mode = ce_mode_from_stat(ce, st.st_mode);
 
 		if (patch->is_new < 0)
 			patch->is_new = 0;
