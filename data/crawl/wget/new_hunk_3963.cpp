    {
      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, uerrmsg (result));
      freeurl (u, 1);
      if (redirections)
	string_set_free (redirections);
      free (url);
      return result;
    }
