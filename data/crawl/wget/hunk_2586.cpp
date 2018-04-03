   if (RAND_status () != 1)
     {
       logprintf (LOG_NOTQUIET,
-		 _("Could not seed PRNG; consider using --random-file.\n"));
+                 _("Could not seed PRNG; consider using --random-file.\n"));
       goto error;
     }
 
