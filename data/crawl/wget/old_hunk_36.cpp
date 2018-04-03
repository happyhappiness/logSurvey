    {
      logprintf (LOG_VERBOSE, _("idn_encode failed (%d): %s\n"), ret,
                 quote (idn2_strerror (ret)));
      ascii_encoded = NULL;
    }

  xfree (lower);

  return ascii_encoded;
}

/* Try to decode an "ASCII encoded" host. Return the new domain in the locale
