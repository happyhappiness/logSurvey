                     bad = 0;
                 }
               if (bad)
-                fatal (NILF, _("Couldn't change back to original directory."));
+                O (fatal, NILF,
+                   _("Couldn't change back to original directory."));
             }
 
           ++restarts;
