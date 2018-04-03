
  switch (url->scheme)
    {
      case SCHEME_HTTP:  scheme_str = "SCHEME_HTTP";    break;
#ifdef HAVE_SSL
      case SCHEME_HTTPS: scheme_str = "SCHEME_HTTPS";   break;
      case SCHEME_FTPS:  scheme_str = "SCHEME_FTPS";    break;
#endif
      case SCHEME_FTP:   scheme_str = "SCHEME_FTP";     break;
      default:           scheme_str = "SCHEME_INVALID"; break;
    }

  fprintf (fp, "%s\t%s\t%s\t%i\t%s\t%s\t%s\t%s",
