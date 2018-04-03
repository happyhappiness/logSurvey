
  common_name[0] = '\0';
  X509_NAME_get_text_by_NID (X509_get_subject_name (cert),
                             NID_commonName, common_name, sizeof (common_name));
  if (!pattern_match (common_name, host))
    {
      logprintf (LOG_NOTQUIET, _("\
%s: certificate common name `%s' doesn't match requested host name `%s'.\n"),
                 severity, escnonprint (common_name), escnonprint (host));
      success = false;
    }

  if (success)
    DEBUGP (("X509 certificate successfully verified and matches host %s\n",
             escnonprint (host)));
  X509_free (cert);

 no_cert:
  if (opt.check_cert && !success)
    logprintf (LOG_NOTQUIET, _("\
To connect to %s insecurely, use `--no-check-certificate'.\n"),
               escnonprint (host));

  /* Allow --no-check-cert to disable certificate checking. */
  return opt.check_cert ? success : true;
