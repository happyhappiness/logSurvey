 		      0,
 		      TRUE,
 		      DUPLICATE_SAME_ACCESS) == FALSE) {
-    fatal (NILF, _("create_child_process: DuplicateHandle(In) failed (e=%d)\n"),
+    fatal (NILF, _("create_child_process: DuplicateHandle(In) failed (e=%ld)\n"),
 	   GetLastError());
 
   }
