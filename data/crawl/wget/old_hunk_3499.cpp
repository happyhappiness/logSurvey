
static int verify_callback PARAMS ((int, X509_STORE_CTX *));

static void
ssl_init_prng (void)
{
#if SSLEAY_VERSION_NUMBER >= 0x00905100
  if (RAND_status () == 0)
    {
      char rand_file[256];
      time_t t;
      long l,seed;

      t = time(NULL);
      /* gets random data from egd if opt.sslegdsock was set */
      if (opt.sslegdsock != NULL)
	RAND_egd(opt.sslegdsock);
      /* gets the file ~/.rnd or $RANDFILE if set */
      RAND_file_name(rand_file, 256);
      if (rand_file != NULL)
	{
	  /* Seed as much as 1024 bytes from RAND_file_name */
	  RAND_load_file(rand_file, 1024);
	}
      /* Seed in time (mod_ssl does this) */
      RAND_seed((unsigned char *)&t, sizeof(time_t));
      /* Initialize system's random number generator */
      RAND_bytes((unsigned char *)&seed, sizeof(long));
#ifndef WINDOWS
      srand48(seed);
      while (RAND_status () == 0)
	{
	  /* Repeatedly seed the PRNG using the system's random number
	     generator until it has been seeded with enough data.  */
	  l = lrand48();
	  RAND_seed((unsigned char *)&l, sizeof(long));
	}
#else /* WINDOWS */
      RAND_screen();
      if (RAND_status() == 0)
        /* Here we should probably disable the whole ssl protocol ? HEH */
        DEBUGP (("SSL random data generator not seeded correctly, %i",RAND_status()));
#endif /* WINDOWS */
      if (rand_file != NULL)
	{
	  /* Write a rand_file */
	  RAND_write_file(rand_file);
	}
    }
#endif /* SSLEAY_VERSION_NUMBER >= 0x00905100 */
  return;
}


/* Creates a SSL Context and sets some defaults for it */
uerr_t
init_ssl (SSL_CTX **ctx)
