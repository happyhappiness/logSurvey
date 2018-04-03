    The output is written into VARIABLE_BUFFER starting at O.  */
 
 /* Note this absorbs a semicolon and is safe to use in conditionals.  */
-#define BADARGS(func)                                                         \
+#define BADARGS(func)  do {                                                   \
   if (reading_filename != 0)                                                  \
     makefile_fatal (reading_filename, *reading_lineno_ptr,                    \
 		    "insufficient arguments to function `%s'",                \
 		    func);                                                    \
   else                                                                        \
-    fatal ("insufficient arguments to function `%s'", func)
+    fatal ("insufficient arguments to function `%s'", func); } while (0)
 
 static char *
 expand_function (o, function, text, end)