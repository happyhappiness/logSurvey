 				 */
 				pos = cache_name_pos(ent->name, ent->len);
 				if (0 <= pos)
-					die("bug in show-killed-files");
+					die("BUG: killed-file %.*s not found",
+						ent->len, ent->name);
 				pos = -pos - 1;
 				while (pos < active_nr &&
 				       ce_stage(active_cache[pos]))