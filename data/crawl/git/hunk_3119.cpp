 	memset(&signature_check, 0, sizeof(signature_check));
 
 	ret = check_commit_signature(lookup_commit(sha1), &signature_check);
-
-	if (verbose && signature_check.payload)
-		fputs(signature_check.payload, stdout);
-
-	if (signature_check.gpg_output)
-		fputs(signature_check.gpg_output, stderr);
+	print_signature_buffer(&signature_check, verbose ? GPG_VERIFY_VERBOSE : 0);
 
 	signature_check_clear(&signature_check);
 	return ret;
