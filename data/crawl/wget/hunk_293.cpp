         {
           if (! warc_start_cdx_file ())
             {
-              logprintf (LOG_NOTQUIET, _("Could not open CDX file for output.\n"));
+              logprintf (LOG_NOTQUIET,
+                         _("Could not open CDX file for output.\n"));
               exit(1);
             }
         }
