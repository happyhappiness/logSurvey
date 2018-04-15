     exit_usage (argv[0], 1);
   }
 
+  c = NULL;
+  status = lcc_connect (address, &c);
+  if (status != 0) {
+    fprintf (stderr, "ERROR: Failed to connect to daemon at %s: %s.\n",
+        address, strerror (errno));
+    return (1);
+  }
+
   if (strcasecmp (argv[optind], "flush") == 0)
-    status = flush (address, argc - optind, argv + optind);
+    status = flush (c, argc - optind, argv + optind);
   else {
     fprintf (stderr, "%s: invalid command: %s\n", argv[0], argv[optind]);
     return (1);
   }
 
+  LCC_DESTROY (c);
+
   if (status != 0)
     return (status);
   return (0);