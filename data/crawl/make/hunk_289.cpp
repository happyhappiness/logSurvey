         filename = expanded;
     }
 
-  ebuf.fp = fopen (filename, "r");
+  ENULLLOOP (ebuf.fp, fopen (filename, "r"));
+
   /* Save the error code so we print the right message later.  */
   makefile_errno = errno;
 
+  /* Check for unrecoverable errors: out of mem or FILE slots.  */
+  switch (makefile_errno)
+    {
+#ifdef EMFILE
+    case EMFILE:
+#endif
+#ifdef ENFILE
+    case ENFILE:
+#endif
+    case ENOMEM:
+      fatal (reading_file, "%s", strerror (makefile_errno));
+    }
+
   /* If the makefile wasn't found and it's either a makefile from
      the 'MAKEFILES' variable or an included makefile,
      search the included makefile search path for this makefile.  */
