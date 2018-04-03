
      if (opt.encoding_remote && !check_encoding_name (opt.encoding_remote))
        opt.encoding_remote = NULL;
    }
#else
  if (opt.enable_iri || opt.locale || opt.encoding_remote)
