 		const char *refname = refnames->items[i].string;
 
 		if (delete_ref(refname, NULL, 0))
-			result |= error(_("Could not remove branch %s"), refname);
+			result |= error(_("could not remove reference %s"), refname);
 	}
 
 	return result;