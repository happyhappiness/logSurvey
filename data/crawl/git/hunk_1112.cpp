 
 	/* And check the encoding */
 	if (encoding_is_utf8 && !verify_utf8(&buffer))
-		fprintf(stderr, commit_utf8_warn);
+		fprintf(stderr, _(commit_utf8_warn));
 
 	if (sign_commit && do_sign_commit(&buffer, sign_commit))
 		return -1;
