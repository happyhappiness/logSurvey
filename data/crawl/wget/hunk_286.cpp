 
   fprintf (warc_tmp, "software: Wget/%s (%s)\r\n", version_string, OS_TYPE);
   fprintf (warc_tmp, "format: WARC File Format 1.0\r\n");
-  fprintf (warc_tmp, "conformsTo: http://bibnum.bnf.fr/WARC/WARC_ISO_28500_version1_latestdraft.pdf\r\n");
+  fprintf (warc_tmp,
+"conformsTo: http://bibnum.bnf.fr/WARC/WARC_ISO_28500_version1_latestdraft.pdf\r\n");
   fprintf (warc_tmp, "robots: %s\r\n", (opt.use_robots ? "classic" : "off"));
   fprintf (warc_tmp, "wget-arguments: %s\r\n", program_argstring);
   /* Add the user headers, if any. */
