           {
             HANDLE hPID;
             int err;
+            exit_code = 0;
+            exit_sig = 0;
+            coredump = 0;
 
             /* wait for anything to finish */
-            if (hPID = process_wait_for_any()) {
+            hPID = process_wait_for_any();
+            if (hPID)
+              {
 
-              /* was an error found on this process? */
-              err = process_last_err(hPID);
+                /* was an error found on this process? */
+                err = process_last_err(hPID);
 
-              /* get exit data */
-              exit_code = process_exit_code(hPID);
+                /* get exit data */
+                exit_code = process_exit_code(hPID);
 
-              if (err)
-                fprintf(stderr, "make (e=%d): %s",
-                  exit_code, map_windows32_error_to_string(exit_code));
+                if (err)
+                  fprintf(stderr, "make (e=%d): %s",
+                          exit_code, map_windows32_error_to_string(exit_code));
 
-              /* signal */
-              exit_sig = process_signal(hPID);
+                /* signal */
+                exit_sig = process_signal(hPID);
 
-              /* cleanup process */
-              process_cleanup(hPID);
+                /* cleanup process */
+                process_cleanup(hPID);
 
-              coredump = 0;
-            }
-            pid = (int) hPID;
+                coredump = 0;
+              }
+            pid = (pid_t) hPID;
           }
 #endif /* WINDOWS32 */
 	}
