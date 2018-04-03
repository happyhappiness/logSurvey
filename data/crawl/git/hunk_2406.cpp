 	const char *hex, *body;
 	const char *msg;
 
-	hex = find_unique_abbrev(get_object_hash(commit->object), DEFAULT_ABBREV);
+	hex = find_unique_abbrev(commit->object.oid.hash, DEFAULT_ABBREV);
 	printf(_("HEAD is now at %s"), hex);
 	msg = logmsg_reencode(commit, NULL, get_log_output_encoding());
 	body = strstr(msg, "\n\n");
