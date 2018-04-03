 		use_message = edit_message;
 	if (amend && !use_message)
 		use_message = "HEAD";
+	if (!use_message && renew_authorship)
+		die("--reset-author can be used only with -C, -c or --amend.");
 	if (use_message) {
 		unsigned char sha1[20];
 		static char utf8[] = "UTF-8";
