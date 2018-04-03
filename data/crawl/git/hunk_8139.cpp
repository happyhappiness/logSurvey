 static NORETURN void die_nicely(const char *err, va_list params)
 {
 	static int zombie;
-	va_list x_params;
+	char message[2 * PATH_MAX];
 
-	va_copy(x_params, params);
+	vsnprintf(message, sizeof(message), err, params);
 	fputs("fatal: ", stderr);
-	vfprintf(stderr, err, params);
+	fputs(message, stderr);
 	fputc('\n', stderr);
 
 	if (!zombie) {
 		zombie = 1;
-		write_crash_report(err, x_params);
+		write_crash_report(message);
 	}
-	va_end(x_params);
 	exit(128);
 }
 