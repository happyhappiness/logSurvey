 	  coredump = 0;
 #endif /* _AMIGA */
 #ifdef WINDOWS32
-         {
-           HANDLE hPID;
-           int err;
-
-           /* wait for anything to finish */
-           if (hPID = process_wait_for_any()) {
+      {
+        HANDLE hPID;
+        int err;
 
-             /* was an error found on this process? */
-             err = process_last_err(hPID);
+        /* wait for anything to finish */
+        if (hPID = process_wait_for_any()) {
 
-             /* get exit data */
-             exit_code = process_exit_code(hPID);
+          /* was an error found on this process? */
+          err = process_last_err(hPID);
 
-             if (err)
-               fprintf(stderr, "make (e=%d): %s",
-                       exit_code, map_windows32_error_to_string(exit_code));
+          /* get exit data */
+          exit_code = process_exit_code(hPID);
 
-             exit_sig = process_signal(hPID);
+          if (err)
+            fprintf(stderr, "make (e=%d): %s",
+              exit_code, map_windows32_error_to_string(exit_code));
 
-             /* cleanup process */
-             process_cleanup(hPID);
+          /* signal */
+          exit_sig = process_signal(hPID);
 
-             if (dos_batch_file) {
-               remove (dos_bname);
-               remove (dos_bename);
-               dos_batch_file = 0;
-             }
+          /* cleanup process */
+          process_cleanup(hPID);
 
-             coredump = 0;
-           }
-           pid = (int) hPID;
-         }
+          coredump = 0;
+        }
+        pid = (int) hPID;
+      }
 #endif /* WINDOWS32 */
 #endif	/* Not __MSDOS__ */
 	}
