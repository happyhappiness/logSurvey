 {
   return ar_name_equal (name, mem, truncated) ? date : 0;
 }
+#endif /* !VMS */
 
 /* Set the archive-member NAME's modtime to now.  */
 
+#ifdef VMS
+int
+ar_touch (name)  
+     char *name;
+{
+  error ("touch archive member is not available on VMS");
+  return -1;
+}
+#else
 int
 ar_touch (name)
      char *name;
