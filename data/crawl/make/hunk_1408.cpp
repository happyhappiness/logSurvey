 
              if (err)
                fprintf(stderr, "make (e=%d): %s",
-                       exit_code, map_win32_error_to_string(exit_code));
+                       exit_code, map_windows32_error_to_string(exit_code));
 
              exit_sig = process_signal(hPID);
 
