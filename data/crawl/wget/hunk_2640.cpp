     struct urlpos *dry;
     for (dry = links; dry; dry = dry->next)
       if (dry->convert != CO_NOCONVERT)
-	++dry_count;
+        ++dry_count;
     if (!dry_count)
       {
-	logputs (LOG_VERBOSE, _("nothing to do.\n"));
-	return;
+        logputs (LOG_VERBOSE, _("nothing to do.\n"));
+        return;
       }
   }
 
