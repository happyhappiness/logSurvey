      return URLERROR;
    }

  /*printf ("[Retrieving %s with %s (UTF-8=%d)\n", url, get_remote_charset (), utf8_encoded);*/

  if (!refurl)
    refurl = opt.referer;

