 	 * Remote HEAD must be a symref (not exactly foolproof; a remote
 	 * symlink to a symref will look like a symref)
 	 */
-	fetch_symref("HEAD", &symref, head_sha1);
+	fetch_symref("HEAD", &symref, &head_oid);
 	if (!symref)
 		return error("Remote HEAD is not a symref");
 
