     }
   }
 
-  return flush(address, plugin, ident_str, timeout);
-}
+  if (optind >= argc) {
+    fprintf (stderr, "%s: missing command\n", argv[0]);
+    exit_usage (argv[0], 1);
+  }
+
+  if (strcasecmp (argv[optind], "flush") == 0)
+    status = flush (address, argc - optind, argv + optind);
+  else {
+    fprintf (stderr, "%s: invalid command: %s\n", argv[0], argv[optind]);
+    return (1);
+  }
+
+  if (status != 0)
+    return (status);
+  return (0);
+} /* main */
 
 /* vim: set sw=2 ts=2 tw=78 expandtab : */
 