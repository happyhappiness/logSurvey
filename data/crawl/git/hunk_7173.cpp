 		return 0;
 	}
 	if (index_path(ce->sha1, path, st, 1))
-		die("unable to index file %s", path);
+		return error("unable to index file %s", path);
 	if (ignore_case && alias && different_name(ce, alias))
 		ce = create_alias_ce(ce, alias);
 	ce->ce_flags |= CE_ADDED;
 	if (add_index_entry(istate, ce, ADD_CACHE_OK_TO_ADD|ADD_CACHE_OK_TO_REPLACE))
-		die("unable to add %s to index",path);
+		return error("unable to add %s to index",path);
 	if (verbose)
 		printf("add '%s'\n", path);
 	return 0;