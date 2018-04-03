 bool
 ssl_init ()
 {
+  const char *ca_directory;
+  DIR *dir;
+
   gnutls_global_init ();
   gnutls_certificate_allocate_credentials (&credentials);
+
+  ca_directory = opt.ca_directory ? opt.ca_directory : "/etc/ssl/certs";
+
+  dir = opendir (ca_directory);
+  if (dir == NULL)
+    {
+      if (opt.ca_directory)
+        logprintf (LOG_NOTQUIET, _("ERROR: Cannot open directory %s.\n"),
+                   opt.ca_directory);
+    }
+  else
+    {
+      struct dirent *dent;
+      while ((dent = readdir (dir)) != NULL)
+        {
+          struct stat st;
+          char *ca_file;
+          asprintf (&ca_file, "%s/%s", ca_directory, dent->d_name);
+
+          stat (ca_file, &st);
+
+          if (S_ISREG (st.st_mode))
+            gnutls_certificate_set_x509_trust_file (credentials, ca_file,
+                                                    GNUTLS_X509_FMT_PEM);
+
+          free (ca_file);
+        }
+
+      closedir (dir);
+    }
+
   if (opt.ca_cert)
     gnutls_certificate_set_x509_trust_file (credentials, opt.ca_cert,
                                             GNUTLS_X509_FMT_PEM);
