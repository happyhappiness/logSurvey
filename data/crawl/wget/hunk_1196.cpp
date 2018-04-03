     {
       logprintf (LOG_NOTQUIET, _("\
 %s: certificate common name %s doesn't match requested host name %s.\n"),
-                 severity, quote (escnonprint (common_name)), quote (escnonprint (host)));
+                 severity, quote (common_name), quote (host));
       success = false;
     }
 
   if (success)
     DEBUGP (("X509 certificate successfully verified and matches host %s\n",
-             escnonprint (host)));
+             quotearg_style (escape_quoting_style, host)));
   X509_free (cert);
 
  no_cert:
   if (opt.check_cert && !success)
     logprintf (LOG_NOTQUIET, _("\
 To connect to %s insecurely, use `--no-check-certificate'.\n"),
-               escnonprint (host));
+               quotearg_style (escape_quoting_style, host));
 
   /* Allow --no-check-cert to disable certificate checking. */
   return opt.check_cert ? success : true;
 changeset 883844a4ac33).
 src/ChangeLog                    |   6 +++
 src/http.c                       |  70 +++++++++++++--------------
 tests/ChangeLog                  |   8 +++-
 tests/Makefile.am                |   1 +
 tests/Test-proxied-https-auth.px | 101 +++++++++++++++++++++++++++++++++++++++
 5 files changed, 150 insertions(+), 36 deletions(-)
 create mode 100755 tests/Test-proxied-https-auth.px
