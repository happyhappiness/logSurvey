           pfatal_with_name (_("dup jobserver"));
 
         error (NILF,
-               _("warning: jobserver unavailable (using -j1).  Add `+' to parent make rule."));
+               _("warning: jobserver unavailable: using -j1.  Add `+' to parent make rule."));
         job_slots = 1;
       }
 
