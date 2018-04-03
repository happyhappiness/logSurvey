 	}
 	if (!author) {
 		warning(_("Missing author: %s"),
-		    sha1_to_hex(commit->object.sha1));
+		    oid_to_hex(&commit->object.oid));
 		return;
 	}
 	if (log->user_format) {
