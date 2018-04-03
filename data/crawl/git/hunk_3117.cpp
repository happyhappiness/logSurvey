 		return error("%s: cannot verify a non-commit object of type %s.",
 				name, typename(type));
 
-	ret = run_gpg_verify(sha1, buf, size, verbose);
+	ret = run_gpg_verify(sha1, buf, size, flags);
 
 	free(buf);
 	return ret;
