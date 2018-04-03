 
 	if (active_cache_changed &&
 	    write_locked_index(&the_index, lock, COMMIT_LOCK))
-		return error(_("Unable to write index."));
+		return err(o, _("Unable to write index."));
 
 	return clean ? 0 : 1;
 }