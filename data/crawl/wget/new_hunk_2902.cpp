    }
}

/* Create an SSL Context and set default paths etc.  Called the first
   time an HTTP download is attempted.

   Returns 0 on success, non-zero otherwise.  */

int
ssl_init ()
{
  SSL_METHOD *meth;

  if (ssl_ctx)
    /* The SSL has already been initialized. */
    return 1;

  /* Init the PRNG.  If that fails, bail out.  */
  init_prng ();
  if (RAND_status () != 1)
    {
      logprintf (LOG_NOTQUIET,
		 _("Could not seed PRNG; consider using --random-file.\n"));
      goto error;
    }

  SSL_library_init ();
  SSL_load_error_strings ();
  SSLeay_add_all_algorithms ();
  SSLeay_add_ssl_algorithms ();

  switch (opt.secure_protocol)
    {
    case secure_protocol_auto:
