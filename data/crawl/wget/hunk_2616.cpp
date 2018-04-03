 	  wgint bytes_remaining = dp->total_length - bytes_displayed;
 	  /* The quantity downloaded in this download run. */
 	  wgint bytes_sofar = bytes_displayed - dp->initial_length;
-	  int eta = (int) (dltime * bytes_remaining / bytes_sofar + 0.5);
-	  logprintf (LOG_VERBOSE, " %s", eta_to_human_short (eta, true));
+	  double eta = dltime * bytes_remaining / bytes_sofar;
+	  if (eta < INT_MAX - 1)
+	    logprintf (LOG_VERBOSE, " %s",
+		       eta_to_human_short ((int) (eta + 0.5), true));
 	}
     }
   else
