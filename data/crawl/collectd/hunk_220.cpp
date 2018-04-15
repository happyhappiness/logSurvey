     return (1);
   }
 
-  if (strcasecmp (argv[optind], "flush") == 0)
+  if (strcasecmp (argv[optind], "getval") == 0)
+    status = getval (c, argc - optind, argv + optind);
+  else if (strcasecmp (argv[optind], "flush") == 0)
     status = flush (c, argc - optind, argv + optind);
   else {
     fprintf (stderr, "%s: invalid command: %s\n", argv[0], argv[optind]);