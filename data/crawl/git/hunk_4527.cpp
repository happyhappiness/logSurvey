 	}
 
 	if (read_cache() < 0)
-		return error("Could not read index");
+		return error(_("Could not read index"));
 
 	result = refresh_index(&the_index, (flags), NULL, NULL,
 			       "Unstaged changes after reset:") ? 1 : 0;
