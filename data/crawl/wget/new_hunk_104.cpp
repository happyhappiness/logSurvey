  X509_free (cert);

 no_cert:
  if (opt.check_cert == CHECK_CERT_ON && !success)
    logprintf (LOG_NOTQUIET, _("\
To connect to %s insecurely, use `--no-check-certificate'.\n"),
               quotearg_style (escape_quoting_style, host));

  return opt.check_cert == CHECK_CERT_ON ? success : true;
}

/*
