 		const char *email, unsigned long timestamp, int tz,
 		const char *message, void *cb_data)
 {
+	const char *refname = cb_data;
+
 	if (verbose)
 		fprintf(stderr, "Checking reflog %s->%s\n",
 			sha1_to_hex(osha1), sha1_to_hex(nsha1));
 
-	fsck_handle_reflog_sha1(osha1);
-	fsck_handle_reflog_sha1(nsha1);
+	fsck_handle_reflog_sha1(refname, osha1);
+	fsck_handle_reflog_sha1(refname, nsha1);
 	return 0;
 }
 
 static int fsck_handle_reflog(const char *logname, const unsigned char *sha1, int flag, void *cb_data)
 {
-	for_each_reflog_ent(logname, fsck_handle_reflog_ent, NULL);
+	for_each_reflog_ent(logname, fsck_handle_reflog_ent, (void *)logname);
 	return 0;
 }
 