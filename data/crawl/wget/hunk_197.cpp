       err = gnutls_protocol_set_priority (session, allowed_protocols);
       break;
 
+    case secure_protocol_tlsv1_1:
+      allowed_protocols[0] = GNUTLS_TLS1_1;
+      allowed_protocols[1] = GNUTLS_TLS1_2;
+      err = gnutls_protocol_set_priority (session, allowed_protocols);
+      break;
+
+    case secure_protocol_tlsv1_2:
+      allowed_protocols[0] = GNUTLS_TLS1_2;
+      err = gnutls_protocol_set_priority (session, allowed_protocols);
+      break;
+
     default:
+      logprintf (LOG_NOTQUIET, _("GnuTLS: unimplemented 'secure-protocol' option value %d\n"), opt.secure_protocol);
+      logprintf (LOG_NOTQUIET, _("Please report this issue to bug-wget@gnu.org\n"));
       abort ();
     }
 #endif
