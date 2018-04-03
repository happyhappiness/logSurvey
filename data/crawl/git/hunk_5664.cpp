 	use(sizeof(struct pack_header));
 }
 
-static void bad_object(unsigned long offset, const char *format,
-		       ...) NORETURN __attribute__((format (printf, 2, 3)));
+static NORETURN void bad_object(unsigned long offset, const char *format,
+		       ...) __attribute__((format (printf, 2, 3)));
 
 static void bad_object(unsigned long offset, const char *format, ...)
 {
