               FILE *local_file;
 
               /* Check the digest.  */
-              local_file = fopen (filename, "rb");
+              local_file = fopen (destname, "rb");
               if (!local_file)
                 {
                   logprintf (LOG_NOTQUIET, _("Could not open downloaded file.\n"));
                   continue;
                 }
 
-              logprintf (LOG_VERBOSE, _("Computing size for %s\n"), quote (filename));
+              logprintf (LOG_VERBOSE, _("Computing size for %s\n"), quote (destname));
 
               if (!mfile->size)
                 {
