 
   nurl = argc - optind;
 
+  /* If we do not have Debug support compiled in AND Wget is invoked with the
+   * --debug switch, instead of failing, we silently turn it into a no-op. For
+   *  this no-op, we explicitly set opt.debug to false and hence none of the
+   *  Debug output messages will be printed.
+   */
+#ifndef ENABLE_DEBUG
+  if (opt.debug)
+    {
+      fprintf (stderr, _("Debugging support not compiled in. "
+                         "Ignoring --debug flag.\n"));
+      opt.debug = false;
+    }
+#endif
+
   /* All user options have now been processed, so it's now safe to do
      interoption dependency checks. */
-
   if (opt.noclobber && opt.convert_links)
     {
       fprintf (stderr,
