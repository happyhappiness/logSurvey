 	if (remote_is_branch
 	    && !strcmp(local, shortname)
 	    && !origin) {
-		warning("Not setting branch %s as its own upstream.",
+		warning(_("Not setting branch %s as its own upstream."),
 			local);
 		return;
 	}
