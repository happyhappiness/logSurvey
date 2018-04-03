 {
 	FILE *f = fopen(path, "w");
 	if (!f)
-		die("cannot open pid file %s: %s", path, strerror(errno));
+		die_errno("cannot open pid file '%s'", path);
 	if (fprintf(f, "%"PRIuMAX"\n", (uintmax_t) getpid()) < 0 || fclose(f) != 0)
-		die("failed to write pid file %s: %s", path, strerror(errno));
+		die_errno("failed to write pid file '%s'", path);
 }
 
 static int serve(char *listen_addr, int listen_port, struct passwd *pass, gid_t gid)
