
  if (RAND_status () == 0)
    {
      logprintf (LOG_NOTQUIET,
		 _("Could not seed OpenSSL PRNG; disabling SSL.\n"));
      scheme_disable (SCHEME_HTTPS);
    }
#endif /* SSLEAY_VERSION_NUMBER >= 0x00905100 */
