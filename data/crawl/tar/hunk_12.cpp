   if (verbose_option <= 1)
     {
       /* Just the fax, mam.  */
-      fprintf (stdlis, "%s\n", quotearg (temp_name));
+      fputs (quotearg (temp_name), stdlis);
+      if (show_transformed_names_option && st->had_trailing_slash)
+	fputc ('/', stdlis);
+      fputc ('\n', stdlis);
     }
   else
     {
