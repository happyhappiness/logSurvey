 #endif
   if (opt.output_document)
     {
-      if (opt.convert_links
+      if ((opt.convert_links || opt.convert_file_only)
           && (nurl > 1 || opt.page_requisites || opt.recursive))
         {
           fputs (_("\
-Cannot specify both -k and -O if multiple URLs are given, or in combination\n\
+Cannot specify both -k or --convert-file-only and -O if multiple URLs are given, or in combination\n\
 with -p or -r. See the manual for details.\n\n"), stderr);
           print_usage (1);
           exit (WGET_EXIT_GENERIC_ERROR);
