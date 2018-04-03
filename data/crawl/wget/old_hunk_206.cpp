    case secure_protocol_tlsv1:
      meth = TLSv1_client_method ();
      break;
#if OPENSSL_VERSION_NUMBER >= 0x01001000
    case secure_protocol_tlsv1_1:
      meth = TLSv1_1_client_method ();
      break;
    case secure_protocol_tlsv1_2:
      meth = TLSv1_2_client_method ();
      break;
#endif
    default:
      abort ();
