    return;
#endif

  /* Still not enough randomness, most likely because neither
     /dev/random nor EGD were available.  Resort to a simple and
     stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
     cryptographically weak, but people who care about strong
     cryptography should install /dev/random (default on Linux) or
     specify their own source of randomness anyway.  */

  logprintf (LOG_VERBOSE, _("Warning: using a weak random seed.\n"));

  while (RAND_status () == 0 && maxrand-- > 0)
    {
