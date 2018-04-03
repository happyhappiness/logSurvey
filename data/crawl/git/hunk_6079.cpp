 	}
 	printf("Removing stale temporary file %s\n", fullpath);
 	if (!show_only)
-		unlink(fullpath);
+		unlink_or_warn(fullpath);
 	return 0;
 }
 
