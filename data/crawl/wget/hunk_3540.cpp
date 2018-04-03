     fwrite (p, 1, fm->length - (p - fm->content), fp);
   fclose (fp);
   read_file_free (fm);
-  logputs (LOG_VERBOSE, _("done.\n"));
+  logprintf (LOG_VERBOSE,
+	     _("%d-%d\n"), to_file_count, to_url_count);
 }
 
 /* Construct and return a malloced copy of the relative link from two
