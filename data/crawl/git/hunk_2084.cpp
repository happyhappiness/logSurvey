 	int file_done = 0;
 
 	if (!f) {
-		error("cannot open mbox %s", file);
+		error_errno("cannot open mbox %s", file);
 		goto out;
 	}
 
