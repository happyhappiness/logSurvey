     int count = 0;
     urlpos *dry = l;
     for (dry = l; dry; dry = dry->next)
-      if (dry->flags & (UABS2REL | UREL2ABS))
+      if (dry->convert != CO_NOCONVERT)
 	++count;
     if (!count)
       {
-	logprintf (LOG_VERBOSE, _("Nothing to do while converting %s.\n"),
-		   file);
+	logputs (LOG_VERBOSE, _("nothing to do.\n"));
 	return;
       }
   }
 
-  logprintf (LOG_VERBOSE, _("Converting %s... "), file);
-
   fm = read_file (file);
   if (!fm)
     {
