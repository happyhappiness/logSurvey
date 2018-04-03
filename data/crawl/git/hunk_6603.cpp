 	strbuf_release(&two);
 
 	fclose(f);
-	if (out)
-		fclose(out);
+	if (wrerror)
+		error("There were errors while writing %s (%s)",
+		      path, strerror(wrerror));
+	if (out && fclose(out))
+		wrerror = error("Failed to flush %s: %s",
+				path, strerror(errno));
 	if (sha1)
 		git_SHA1_Final(sha1, &ctx);
 	if (hunk != RR_CONTEXT) {
 		if (output)
 			unlink(output);
 		return error("Could not parse conflict hunks in %s", path);
 	}
+	if (wrerror)
+		return -1;
 	return hunk_no;
 }
 
