        return;

      /*logprintf (LOG_VERBOSE, "Meta tag charset : %s\n", quote (mcharset));*/
      xfree_null (meta_charset);
      meta_charset = mcharset;
    }
  else if (name && 0 == strcasecmp (name, "robots"))
    {
