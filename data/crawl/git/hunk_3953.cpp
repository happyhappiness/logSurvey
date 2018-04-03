 		prime_cache_tree(&active_cache_tree, tree);
 	}
 
-	if (write_cache(newfd, active_cache, active_nr) ||
-	    commit_locked_index(lock))
-		return error(_("Could not write new index file."));
-
 	return 0;
 }
 
