  return ok;
}

/* Print SSL errors. */

void
ssl_print_errors (void) 
{
  unsigned long curerr = 0;
  char errbuff[1024];
  xzero (errbuff);
  while ((curerr = ERR_get_error ()) != 0)
    logprintf (LOG_NOTQUIET, "OpenSSL: %s\n",
	       ERR_error_string (curerr, errbuff));
}

/* Creates a SSL Context and sets some defaults for it */
uerr_t
ssl_init ()
{
  SSL_METHOD *meth = NULL;
  int verify;
  int can_validate;

  if (ssl_ctx)
    return 0;

  /* Init the PRNG.  If that fails, bail out.  */
  ssl_init_prng ();
  if (RAND_status () == 0)
    {
      logprintf (LOG_NOTQUIET,
		 _("Could not seed OpenSSL PRNG; disabling SSL.\n"));
      scheme_disable (SCHEME_HTTPS);
      return SSLERRCTXCREATE;
    }

  SSL_library_init ();
  SSL_load_error_strings ();
  SSLeay_add_all_algorithms ();
