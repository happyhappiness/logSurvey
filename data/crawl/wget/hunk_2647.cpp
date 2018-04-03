   if (!fm)
     {
       logprintf (LOG_NOTQUIET, _("Cannot open %s: %s"),
-		 filename, strerror (errno));
+                 filename, strerror (errno));
       return NULL;
     }
   specs = res_parse (fm->content, fm->length);
