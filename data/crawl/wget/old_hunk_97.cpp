          success = false;
        }
      xfree(sni_hostname);
 crt_deinit:
      gnutls_x509_crt_deinit (cert);
    }
