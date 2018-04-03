      if (!mcharset)
        return;

      /*logprintf (LOG_VERBOSE, "Meta tag charset : %s\n", quote (mcharset));*/

      set_current_charset (mcharset);
      xfree (mcharset);
    }
  else if (name && 0 == strcasecmp (name, "robots"))
