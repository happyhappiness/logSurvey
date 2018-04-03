 }
 
 /* fatal */
-void fatal(message)
-     char *message;
+void
+fatal(char *message)
 {
     fatal_common(message);
     exit(1);
 }
 
 /* fatal with dumping core */
-void fatal_dump(message)
-     char *message;
+void
+fatal_dump(char *message)
 {
     if (message)
 	fatal_common(message);
