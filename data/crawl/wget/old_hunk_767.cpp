      if (!mcharset)
        return;

      logprintf (LOG_VERBOSE, "Meta tag charset : %s\n", quote (mcharset));

      /* sXXXav: Not used yet */
      xfree (mcharset);
    }
  else if (name && 0 == strcasecmp (name, "robots"))
