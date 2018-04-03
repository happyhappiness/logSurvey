     return b ? ((int) (100.0 * a / b + 0.5)) : 0;
 }
 
+/* MinGW needs also a stub of death() */
+void
+death(int sig)
+{
+    fatal ("Not implemented");
+}