           logprintf (LOG_VERBOSE, "Check the locale...\n");
         }
     }
+#else
+  if (opt.enable_iri || opt.locale || opt.encoding_remote)
+    {
+      /* sXXXav : be more specific... */
+      printf(_("This version does not have support for IRIs\n"));
+      exit(1);
+    }
 #endif
 
   if (opt.ask_passwd)
