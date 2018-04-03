  if (ret != IDNA_SUCCESS)
    {
      /* sXXXav : free new when needed ! */
      logprintf (LOG_VERBOSE, _("idn_encode failed (%d): %s\n"), ret,
                 quote (idna_strerror (ret)));
      return NULL;
    }
