      err = gnutls_protocol_set_priority (session, allowed_protocols);
      break;

    default:
      abort ();
    }
#endif
