 static NORETURN void die_nicely(const char *err, va_list params)
 {
 	static int zombie;
+	char message[2 * PATH_MAX];
 
-	vreportf("fatal: ", err, params);
+	vsnprintf(message, sizeof(message), err, params);
+	fputs("fatal: ", stderr);
+	fputs(message, stderr);
+	fputc('\n', stderr);
 
 	if (!zombie) {
-		char message[2 * PATH_MAX];
-
 		zombie = 1;
 		write_crash_report(message);
 		end_packfile();