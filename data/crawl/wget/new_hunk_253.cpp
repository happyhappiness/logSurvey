{
  /* Becomes true if GnuTLS is initialized. */
  static bool ssl_initialized = false;
  const char *ca_directory;
  DIR *dir;
  int ncerts = -1;

  /* GnuTLS should be initialized only once. */
  if (ssl_initialized)
    return true;

  gnutls_global_init ();
  gnutls_certificate_allocate_credentials (&credentials);
  gnutls_certificate_set_verify_flags (credentials,
                                       GNUTLS_VERIFY_ALLOW_X509_V1_CA_CRT);

#if GNUTLS_VERSION_MAJOR >= 3
  if (!opt.ca_directory)
    ncerts = gnutls_certificate_set_x509_system_trust (credentials);
#endif

  /* If GnuTLS version is too old or CA loading failed, fallback to old behaviour.
   * Also use old behaviour if the CA directory is user-provided.  */
  if (ncerts <= 0)
    {
      ca_directory = opt.ca_directory ? opt.ca_directory : "/etc/ssl/certs";
      if ((dir = opendir (ca_directory)) == NULL)
        {
          if (opt.ca_directory && *opt.ca_directory)
            logprintf (LOG_NOTQUIET, _("ERROR: Cannot open directory %s.\n"),
                       opt.ca_directory);
        }
      else
        {
          struct hash_table *inode_map = hash_table_new (196, NULL, NULL);
          struct dirent *dent;
          size_t dirlen = strlen(ca_directory);
          int rc;

          ncerts = 0;

          while ((dent = readdir (dir)) != NULL)
            {
              struct stat st;
              char ca_file[dirlen + strlen(dent->d_name) + 2];

              snprintf (ca_file, sizeof(ca_file), "%s/%s", ca_directory, dent->d_name);
              if (stat (ca_file, &st) != 0)
                continue;

              if (! S_ISREG (st.st_mode))
                continue;

              /* avoid loading the same file twice by checking the inode.  */
              if (hash_table_contains (inode_map, (void *)(intptr_t) st.st_ino))
                continue;

              hash_table_put (inode_map, (void *)(intptr_t) st.st_ino, NULL);
              if ((rc = gnutls_certificate_set_x509_trust_file (credentials, ca_file,
                                                                GNUTLS_X509_FMT_PEM)) <= 0)
                logprintf (LOG_NOTQUIET, _("ERROR: Failed to open cert %s: (%d).\n"),
                           ca_file, rc);
              else
                ncerts += rc;
            }

          hash_table_destroy (inode_map);
          closedir (dir);
        }
    }

  DEBUGP (("Certificates loaded: %d\n", ncerts));

  /* Use the private key from the cert file unless otherwise specified. */
  if (opt.cert_file && !opt.private_key)
    {
