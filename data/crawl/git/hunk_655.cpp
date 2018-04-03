 
 	/* Jump to the end */
 	if (fseek(logfp, 0, SEEK_END) < 0)
-		return error("cannot seek back reflog for %s: %s",
-			     refname, strerror(errno));
+		ret = error("cannot seek back reflog for %s: %s",
+			    refname, strerror(errno));
 	pos = ftell(logfp);
 	while (!ret && 0 < pos) {
 		int cnt;
