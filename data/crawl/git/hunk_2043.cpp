 		 */
 		if (errno == ENOENT)
 			return 0;
-		return error("unable to stat %s: %s",
-			     sha1_to_hex(sha1), strerror(errno));
+		return error_errno("unable to stat %s", sha1_to_hex(sha1));
 	}
 
 	add_recent_object(sha1, st.st_mtime, data);