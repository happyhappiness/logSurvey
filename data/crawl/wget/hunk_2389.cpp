       sleep_between_retrievals (count);
       
       /* Get the current time string.  */
-      tms = time_str (time (NULL));
+      tms = datetime_str (time (NULL));
       
       if (opt.spider && !got_head)
         logprintf (LOG_VERBOSE, _("\
