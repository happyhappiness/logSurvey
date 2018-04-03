 	fprintf(stderr, "%s%s\n", prefix, msg);
 }
 
-static NORETURN void usage_builtin(const char *err)
+static NORETURN void usage_builtin(const char *err, va_list params)
 {
-	fprintf(stderr, "usage: %s\n", err);
+	report("usage: ", err, params);
 	exit(129);
 }
 
