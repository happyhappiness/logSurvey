         switch (glob (name, GLOB_NOSORT|GLOB_ALTDIRFUNC, NULL, &gl))
           {
           case GLOB_NOSPACE:
-            fatal (NILF, _("virtual memory exhausted"));
+            OUT_OF_MEM();
 
           case 0:
             /* Success.  */
