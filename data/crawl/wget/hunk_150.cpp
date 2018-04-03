       opt.always_rest = false;
     }
 
-  if (!nurl && !opt.input_filename)
+  if (!nurl && !opt.input_filename
+#ifdef HAVE_METALINK
+      && !opt.input_metalink
+#endif
+      )
     {
       /* No URL specified.  */
       fprintf (stderr, _("%s: missing URL\n"), exec_name);
