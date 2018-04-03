 		error("There were errors while writing %s (%s)",
 		      path, strerror(io.io.wrerror));
 	if (io.io.output && fclose(io.io.output))
-		io.io.wrerror = error("Failed to flush %s: %s",
-				      path, strerror(errno));
+		io.io.wrerror = error_errno("Failed to flush %s", path);
 
 	if (hunk_no < 0) {
 		if (output)
