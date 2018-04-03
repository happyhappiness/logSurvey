 	} while (ret == Z_OK);
 
 	if (ret != Z_STREAM_END)
-		die("unable to deflate new object %s (%d)", sha1_to_hex(sha1), ret);
+		die("unable to deflate new object %s (%d)", oid_to_hex(oid),
+		    ret);
 	ret = git_deflate_end_gently(&stream);
 	if (ret != Z_OK)
-		die("deflateEnd on object %s failed (%d)", sha1_to_hex(sha1), ret);
-	git_SHA1_Final(parano_sha1, &c);
-	if (hashcmp(sha1, parano_sha1) != 0)
-		die("confused by unstable object source data for %s", sha1_to_hex(sha1));
+		die("deflateEnd on object %s failed (%d)", oid_to_hex(oid),
+		    ret);
+	git_SHA1_Final(parano_oid.hash, &c);
+	if (oidcmp(oid, &parano_oid) != 0)
+		die("confused by unstable object source data for %s",
+		    oid_to_hex(oid));
 
 	close_sha1_file(fd);
 
