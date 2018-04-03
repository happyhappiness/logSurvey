 	}
 }
 
+__attribute__((format (printf, 1, 2)))
 static void logerror(const char *err, ...)
 {
 	va_list params;
