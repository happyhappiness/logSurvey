 	if (finish_command(&gpg) || !len || len < 0)
 		return error("gpg failed to sign the tag");
 
-	if (len < 0)
-		return error("could not read the entire signature from gpg.");
-
 	return 0;
 }
 