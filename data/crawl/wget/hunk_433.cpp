           break;
         case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
         case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
-          logprintf (LOG_NOTQUIET, _("  Self-signed certificate encountered.\n"));
+          logprintf (LOG_NOTQUIET,
+                     _("  Self-signed certificate encountered.\n"));
           break;
         case X509_V_ERR_CERT_NOT_YET_VALID:
           logprintf (LOG_NOTQUIET, _("  Issued certificate not yet valid.\n"));
