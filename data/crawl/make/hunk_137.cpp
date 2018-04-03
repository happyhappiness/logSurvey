         }
 
         if (envp) {
-                if (arr2envblk(envp, &envblk) ==FALSE) {
+                if (arr2envblk(envp, &envblk, &envsize_needed) == FALSE) {
                         pproc->last_err = 0;
                         pproc->lerrno = E_NO_MEM;
                         free( command_line );
+                        if (pproc->last_err == ERROR_INVALID_PARAMETER
+                            && envsize_needed > 32*1024) {
+                                fprintf (stderr, "CreateProcess failed, probably because environment is too large (%d bytes).\n",
+                                         envsize_needed);
+                        }
                         return(-1);
                 }
         }
