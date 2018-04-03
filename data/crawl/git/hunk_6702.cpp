 			sha1_ptr = sha1;
 
 		ce = make_cache_entry(patch->old_mode, sha1_ptr, name, 0, 0);
+		if (!ce)
+			die("make_cache_entry failed for path '%s'", name);
 		if (add_index_entry(&result, ce, ADD_CACHE_OK_TO_ADD))
 			die ("Could not add %s to temporary index", name);
 	}
