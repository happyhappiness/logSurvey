 static void fsck_object_dir(const char *path)
 {
 	int i;
+
+	if (verbose)
+		fprintf(stderr, "Checking object directory\n");
+
 	for (i = 0; i < 256; i++) {
 		static char dir[4096];
 		sprintf(dir, "%s/%02x", path, i);
