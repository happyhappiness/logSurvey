        }
 crt_deinit:
      gnutls_x509_crt_deinit (cert);
   }

 out:
  return opt.check_cert ? success : true;
