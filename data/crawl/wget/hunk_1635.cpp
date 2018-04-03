   if (opt.output_document)
     {
       if (HYPHENP (opt.output_document))
-        output_stream = stdout;
+        {
+#ifdef WINDOWS
+          FILE *result;
+          result = freopen (NULL, "wb", stdout);
+          if (result == NULL)
+            {
+              logputs (LOG_NOTQUIET, _("\
+WARNING: Can't reopen standard output in binary mode;\n\
+         downloaded file may contain inappropriate line endings.\n"));
+            }
+#endif
+          output_stream = stdout;
+        }
       else
         {
           struct_fstat st;
