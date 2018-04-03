{
  /* Becomes true if GnuTLS is initialized. */
  static bool ssl_initialized = false;

  /* GnuTLS should be initialized only once. */
  if (ssl_initialized)
    return true;

  const char *ca_directory;
  DIR *dir;

  gnutls_global_init ();
  gnutls_certificate_allocate_credentials (&credentials);
  gnutls_certificate_set_verify_flags(credentials,
                                      GNUTLS_VERIFY_ALLOW_X509_V1_CA_CRT);

  ca_directory = opt.ca_directory ? opt.ca_directory : "/etc/ssl/certs";

  dir = opendir (ca_directory);
  if (dir == NULL)
    {
      if (opt.ca_directory && *opt.ca_directory)
        logprintf (LOG_NOTQUIET, _("ERROR: Cannot open directory %s.\n"),
                   opt.ca_directory);
    }
  else
    {
      struct dirent *dent;
      while ((dent = readdir (dir)) != NULL)
        {
          struct stat st;
          char *ca_file;
          asprintf (&ca_file, "%s/%s", ca_directory, dent->d_name);

          stat (ca_file, &st);

          if (S_ISREG (st.st_mode))
            gnutls_certificate_set_x509_trust_file (credentials, ca_file,
                                                    GNUTLS_X509_FMT_PEM);

          free (ca_file);
        }

      closedir (dir);
    }

  /* Use the private key from the cert file unless otherwise specified. */
  if (opt.cert_file && !opt.private_key)
    {
