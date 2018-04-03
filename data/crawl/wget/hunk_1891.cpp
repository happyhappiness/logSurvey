   int i;
 
   printf (_("GNU Wget %s, a non-interactive network retriever.\n"),
-          version_string);
+          VERSION_STRING);
   print_usage ();
 
   for (i = 0; i < countof (help); i++)
