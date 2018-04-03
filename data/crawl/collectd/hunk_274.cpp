     status = getval (c, argc - optind, argv + optind);
   else if (strcasecmp (argv[optind], "flush") == 0)
     status = flush (c, argc - optind, argv + optind);
+  else if (strcasecmp (argv[optind], "listval") == 0)
+    status = listval (c, argc - optind, argv + optind);
   else {
     fprintf (stderr, "%s: invalid command: %s\n", argv[0], argv[optind]);
     return (1);