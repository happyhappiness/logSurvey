#endif
    {
      if (status != 2)
        error (NILF,
               "INTERNAL: Exiting with %u jobserver tokens (should be 0)!",
               jobserver_tokens);
      else
        /* Don't write back the "free" token */
        while (--jobserver_tokens)
