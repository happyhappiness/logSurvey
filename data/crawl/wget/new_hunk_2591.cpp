  if (dp->total_length)
    {
      /* Round to floor value to provide gauge how much data *has*
         been retrieved.  12.8% will round to 12% because the 13% mark
         has not yet been reached.  100% is only shown when done.  */
      int percentage = 100.0 * bytes_displayed / dp->total_length;
      logprintf (LOG_VERBOSE, "%3d%%", percentage);
    }
