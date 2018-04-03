 	    ce_stage(active_cache[pos+1]) != 2 ||
 	    strcmp(active_cache[pos+2]->name, ce->name) ||
 	    ce_stage(active_cache[pos+2]) != 3)
-		return error("path '%s' does not have all three versions",
+		return error(_("path '%s' does not have all three versions"),
 			     ce->name);
 	return 0;
 }
