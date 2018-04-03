      meth = SSLv2_client_method ();
      break;
#endif

#ifndef OPENSSL_NO_SSL3
    case secure_protocol_sslv3:
      meth = SSLv3_client_method ();
      break;
#endif

    case secure_protocol_auto:
    case secure_protocol_pfs:
    case secure_protocol_tlsv1:
      meth = TLSv1_client_method ();
      break;

#if OPENSSL_VERSION_NUMBER >= 0x10001000
    case secure_protocol_tlsv1_1:
      meth = TLSv1_1_client_method ();
      break;

    case secure_protocol_tlsv1_2:
      meth = TLSv1_2_client_method ();
      break;
#else
    case secure_protocol_tlsv1_1:
      logprintf (LOG_NOTQUIET, _("Your OpenSSL version is too old to support TLSv1.1\n"));
      goto error;

    case secure_protocol_tlsv1_2:
      logprintf (LOG_NOTQUIET, _("Your OpenSSL version is too old to support TLSv1.2\n"));
      goto error;
#endif

    default:
      logprintf (LOG_NOTQUIET, _("OpenSSL: unimplemented 'secure-protocol' option value %d\n"), opt.secure_protocol);
      logprintf (LOG_NOTQUIET, _("Please report this issue to bug-wget@gnu.org\n"));
      abort ();
    }

