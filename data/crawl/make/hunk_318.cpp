   return 0;
 }
 
-int
-unload_file (struct file *file)
+void
+unload_file (const char *name)
 {
-  fatal (flocp, "INTERNAL: Cannot unload when load is not supported!");
-  return 0;
+  fatal (NILF, "INTERNAL: Cannot unload when load is not supported!");
 }
 
 #endif  /* MAKE_LOAD */
