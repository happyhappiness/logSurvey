       bytes_this_row -= dp->initial_length % ROW_BYTES;
     rate = calc_rate (bytes_this_row, dltime - dp->last_timer_value, &units);
     logprintf (LOG_VERBOSE, " %4.*f%c",
-	       rate >= 99.95 ? 0 : rate >= 9.995 ? 1 : 2,
-	       rate, names[units]);
+               rate >= 99.95 ? 0 : rate >= 9.995 ? 1 : 2,
+               rate, names[units]);
     dp->last_timer_value = dltime;
   }
 
   if (!last)
     {
       /* Display ETA based on average speed.  Inspired by Vladi
-	 Belperchinov-Shabanski's "wget-new-percentage" patch.  */
+         Belperchinov-Shabanski's "wget-new-percentage" patch.  */
       if (dp->total_length)
-	{
-	  wgint bytes_remaining = dp->total_length - bytes_displayed;
-	  /* The quantity downloaded in this download run. */
-	  wgint bytes_sofar = bytes_displayed - dp->initial_length;
-	  double eta = dltime * bytes_remaining / bytes_sofar;
-	  if (eta < INT_MAX - 1)
-	    logprintf (LOG_VERBOSE, " %s",
-		       eta_to_human_short ((int) (eta + 0.5), true));
-	}
+        {
+          wgint bytes_remaining = dp->total_length - bytes_displayed;
+          /* The quantity downloaded in this download run. */
+          wgint bytes_sofar = bytes_displayed - dp->initial_length;
+          double eta = dltime * bytes_remaining / bytes_sofar;
+          if (eta < INT_MAX - 1)
+            logprintf (LOG_VERBOSE, " %s",
+                       eta_to_human_short ((int) (eta + 0.5), true));
+        }
     }
   else
     {
       /* When done, print the total download time */
       if (dltime >= 10)
-	logprintf (LOG_VERBOSE, "=%s",
-		   eta_to_human_short ((int) (dltime + 0.5), true));
+        logprintf (LOG_VERBOSE, "=%s",
+                   eta_to_human_short ((int) (dltime + 0.5), true));
       else
-	logprintf (LOG_VERBOSE, "=%ss", print_decimal (dltime));
+        logprintf (LOG_VERBOSE, "=%ss", print_decimal (dltime));
     }
 }
 
