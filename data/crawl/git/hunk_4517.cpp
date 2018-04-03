 			  git_committer_info(IDENT_ERROR_ON_NO_NAME));
 
 	if (header_len > sizeof(header_buf) - 1)
-		die("tag header too big.");
+		die(_("tag header too big."));
 
 	if (!message) {
 		int fd;
