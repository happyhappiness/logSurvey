           break;
       else
           fprintf(stderr,
-                  _("make reaped child pid %d, still waiting for pid %d\n"),
-                  hWaitPID, hPID);
+                  _("make reaped child pid %ld, still waiting for pid %ld\n"),
+                  (DWORD)hWaitPID, (DWORD)hPID);
     }
 
   /* return child's exit code as our exit code */
