 		 * checked out.
 		 */
 		if (S_ISGITLINK(ce->ce_mode))
-			return;
+			return 0;
 		errno = 0;
 	}
 	if (errno == ENOENT)
-		return;
-	die("Entry '%s' not uptodate. Cannot merge.", ce->name);
+		return 0;
+	return error("Entry '%s' not uptodate. Cannot merge.", ce->name);
 }
 
 static void invalidate_ce_path(struct cache_entry *ce)
