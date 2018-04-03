           break;
       else
           fprintf(stderr,
-                  "make reaped child pid %d, still waiting for pid %d\n",
+                  _("make reaped child pid %d, still waiting for pid %d\n"),
                   hWaitPID, hPID);
     }
 
