bool
ssl_init ()
{
  gnutls_global_init ();
  gnutls_certificate_allocate_credentials (&credentials);
  if (opt.ca_cert)
    gnutls_certificate_set_x509_trust_file (credentials, opt.ca_cert,
                                            GNUTLS_X509_FMT_PEM);
