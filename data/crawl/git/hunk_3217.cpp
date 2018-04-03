 	    *type_p = type;
 	if (!refname) {
 		last_errno = errno;
-		error("unable to resolve reference %s: %s",
-			orig_refname, strerror(errno));
+		strbuf_addf(err, "unable to resolve reference %s: %s",
+			    orig_refname, strerror(errno));
 		goto error_return;
 	}
 	/*
