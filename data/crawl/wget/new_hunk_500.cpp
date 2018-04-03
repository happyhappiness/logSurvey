      if (!gnutls_x509_crt_check_hostname (cert, host))
        {
          logprintf (LOG_NOTQUIET,
                     _("The certificate's owner does not match hostname %s\n"),
                     quote (host));
          success = false;
        }
      gnutls_x509_crt_deinit (cert);
