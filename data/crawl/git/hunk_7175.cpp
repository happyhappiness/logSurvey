 	return 0;
 }
 
-static int write_error(void)
+static int write_error(const char *filename)
 {
-	fprintf(stderr, "Failed to write new configuration file\n");
+	error("failed to write new configuration file %s", filename);
 
 	/* Same error code as "failed to rename". */
 	return 4;
