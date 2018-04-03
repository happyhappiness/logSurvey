               hash_table_put (inode_map, (void *)(intptr_t) st.st_ino, NULL);
               if ((rc = gnutls_certificate_set_x509_trust_file (credentials, ca_file,
                                                                 GNUTLS_X509_FMT_PEM)) <= 0)
-                logprintf (LOG_NOTQUIET, _("ERROR: Failed to open cert %s: (%d).\n"),
-                           ca_file, rc);
+                DEBUGP (("WARNING: Failed to open cert %s: (%d).\n", ca_file, rc));
               else
                 ncerts += rc;
             }
