
     - When matching against common names, it should loop over all
       common names and choose the most specific one, i.e. the last
       one, not the first one, which the current code picks.  */

  peer_CN[0] = '\0';
  X509_NAME_get_text_by_NID (X509_get_subject_name (peer_cert),
			     NID_commonName, peer_CN, sizeof (peer_CN));
  if (!pattern_match (peer_CN, host))
    {
      logprintf (LOG_NOTQUIET, _("\
%s: certificate common name `%s' doesn't match requested host name `%s'.\n"),
		 severity, escnonprint (peer_CN), escnonprint (host));
      retval = 0;
      goto out;
    }

  /* The certificate was found, verified, and matched HOST. */
  retval = 1;

 out:
  if (peer_cert)
    X509_free (peer_cert);

  /* Allow --no-check-cert to disable certificate checking. */
  return opt.check_cert ? retval : 1;
}
