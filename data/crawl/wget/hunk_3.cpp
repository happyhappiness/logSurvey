         }
     }
 
+#ifdef HAVE_LIBZ
+  if (opt.always_rest || opt.start_pos >= 0)
+    {
+      if (opt.compression == compression_auto)
+        {
+          /* Compression does not work with --continue or --start-pos.
+             Since compression was not explicitly set, it will be disabled. */
+          opt.compression = compression_none;
+        }
+      else if (opt.compression != compression_none)
+        {
+          fprintf (stderr,
+                   _("Compression does not work with --continue or"
+                     " --start-pos, they will be disabled.\n"));
+          opt.always_rest = false;
+          opt.start_pos = -1;
+        }
+    }
+#endif
+
   if (opt.ask_passwd && opt.passwd)
     {
       fprintf (stderr,
