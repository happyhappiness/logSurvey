 	va_end(params);
 }
 
+#undef error
 int error(const char *err, ...)
 {
 	va_list params;