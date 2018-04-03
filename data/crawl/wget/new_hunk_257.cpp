        }
 crt_deinit:
      gnutls_x509_crt_deinit (cert);
    }
  else
    {
      logprintf (LOG_NOTQUIET, _("Certificate must be X.509\n"));
      success = false;
    }

 out:
  return opt.check_cert ? success : true;
