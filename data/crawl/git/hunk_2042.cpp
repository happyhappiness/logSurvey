 	if (unlink(filename))
 		return (errno == ENOENT
 			? error("no remembered resolution for %s", path)
-			: error("cannot unlink %s: %s", filename, strerror(errno)));
+			: error_errno("cannot unlink %s", filename));
 
 	/*
 	 * Update the preimage so that the user can resolve the