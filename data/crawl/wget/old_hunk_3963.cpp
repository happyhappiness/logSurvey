    {
      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, uerrmsg (result));
      freeurl (u, 1);
      free_slist (redirections);
      free (url);
      return result;
    }
