   if (!fm)
     {
       logprintf (LOG_NOTQUIET, _("Cannot convert links in %s: %s\n"),
-		 file, strerror (errno));
+                 file, strerror (errno));
       return;
     }
 
