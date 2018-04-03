  return ok;
}

/* pass all ssl errors to DEBUGP
   returns the number of printed errors */
int
ssl_printerrors (void) 
{
  int ocerr = 0;
  unsigned long curerr = 0;
  char errbuff[1024];
  xzero (errbuff);
  while ((curerr = ERR_get_error ()) != 0)
    {
      DEBUGP (("OpenSSL: %s\n", ERR_error_string (curerr, errbuff)));
      ++ocerr;
    }
  return ocerr;
}

/* Creates a SSL Context and sets some defaults for it */
uerr_t
init_ssl (SSL_CTX **ctx)
{
  SSL_METHOD *meth = NULL;
  int verify;
  int can_validate;
  SSL_library_init ();
  SSL_load_error_strings ();
  SSLeay_add_all_algorithms ();
