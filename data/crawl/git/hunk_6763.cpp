 
 	if (pretend)
 		;
-	else if (add_index_entry(istate, ce, ADD_CACHE_OK_TO_ADD|ADD_CACHE_OK_TO_REPLACE))
+	else if (add_index_entry(istate, ce, add_option))
 		return error("unable to add %s to index",path);
 	if (verbose && !was_same)
 		printf("add '%s'\n", path);
