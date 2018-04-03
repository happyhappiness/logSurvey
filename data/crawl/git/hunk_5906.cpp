 
 	/* Check for ENOSPC and EIO errors.. */
 	if (fflush(stdout))
-		die("write failure on standard output: %s", strerror(errno));
+		die_errno("write failure on standard output");
 	if (ferror(stdout))
 		die("unknown write failure on standard output");
 	if (fclose(stdout))
-		die("close failed on standard output: %s", strerror(errno));
+		die_errno("close failed on standard output");
 	return 0;
 }
 
