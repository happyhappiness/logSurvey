       else if (streq (p, "recurse"))
         output_sync = OUTPUT_SYNC_RECURSE;
       else
-        fatal (NILF, _("unknown output-sync type '%s'"), p);
+        OS (fatal, NILF, _("unknown output-sync type '%s'"), p);
     }
 
   if (sync_mutex)
