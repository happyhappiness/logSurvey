 		refresh_cache(REFRESH_QUIET);
 
 		if (unmerged_cache()) {
-			error("you need to resolve your current index first");
+			error(_("you need to resolve your current index first"));
 			return 1;
 		}
 
