 		git_SHA1_Final(sha1, &ctx);
 	if (hunk != RR_CONTEXT) {
 		if (output)
-			unlink(output);
+			unlink_or_warn(output);
 		return error("Could not parse conflict hunks in %s", path);
 	}
 	if (wrerror)
