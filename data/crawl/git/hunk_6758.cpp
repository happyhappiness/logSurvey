 	FILE *f = fopen(path, "w");
 	if (!f)
 		die("cannot open pid file %s: %s", path, strerror(errno));
-	if (fprintf(f, "%d\n", getpid()) < 0 || fclose(f) != 0)
+	if (fprintf(f, "%"PRIuMAX"\n", (uintmax_t) getpid()) < 0 || fclose(f) != 0)
 		die("failed to write pid file %s: %s", path, strerror(errno));
 }
 
