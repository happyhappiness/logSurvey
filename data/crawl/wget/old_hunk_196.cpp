    case secure_protocol_auto:
      err = gnutls_priority_set_direct (session, "NORMAL:%COMPAT:-VERS-SSL3.0", NULL);
      break;
    case secure_protocol_sslv2:
    case secure_protocol_sslv3:
      err = gnutls_priority_set_direct (session, "NORMAL:-VERS-TLS-ALL:+VERS-SSL3.0", NULL);
      break;
    case secure_protocol_tlsv1:
      err = gnutls_priority_set_direct (session, "NORMAL:-VERS-SSL3.0", NULL);
      break;
    case secure_protocol_pfs:
      err = gnutls_priority_set_direct (session, "PFS:-VERS-SSL3.0", NULL);
      if (err != GNUTLS_E_SUCCESS)
        /* fallback if PFS is not available */
        err = gnutls_priority_set_direct (session, "NORMAL:-RSA:-VERS-SSL3.0", NULL);
      break;
    default:
      abort ();
    }
#else
