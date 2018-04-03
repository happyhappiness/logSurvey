   return 0;
 }
 
+int
+unload_file (struct file *file)
+{
+  fatal (flocp, "INTERNAL: Cannot unload when load is not supported!");
+  return 0;
+}
+
 #endif  /* MAKE_LOAD */
