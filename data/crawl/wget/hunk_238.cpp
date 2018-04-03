     {
       /* When done, print the total download time */
       if (dltime >= 10)
-        logprintf (LOG_VERBOSE, "=%s",
+        logprintf (LOG_PROGRESS, "=%s",
                    eta_to_human_short ((int) (dltime + 0.5), true));
       else
-        logprintf (LOG_VERBOSE, "=%ss", print_decimal (dltime));
+        logprintf (LOG_PROGRESS, "=%ss", print_decimal (dltime));
     }
 }
 
