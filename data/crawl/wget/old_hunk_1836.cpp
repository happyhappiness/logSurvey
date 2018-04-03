    {
      logprintf (LOG_NOTQUIET, _("\
%s: certificate common name %s doesn't match requested host name %s.\n"),
                 severity, quote (escnonprint (common_name)), quote (escnonprint (host)));
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
src/ChangeLog | 5 +++++
src/ftp.c     | 8 ++++----
2 files changed, 9 insertions(+), 4 deletions(-)
