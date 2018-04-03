            logputs (LOG_VERBOSE, "\n");
        }
    }

  /* Return if we have no intention of further downloading.  */
  if ((!(*dt & RETROKF) && !opt.content_on_error) || head_only)
