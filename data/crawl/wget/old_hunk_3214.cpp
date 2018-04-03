    return;
#endif

  /* Still not enough randomness, presumably because neither random
     file nor EGD have been available.  Use the stupidest possible
     method -- seed OpenSSL's PRNG with the system's PRNG.  This is
     insecure in the cryptographic sense, but people who care about
     security will use /dev/random or their own source of randomness
     anyway.  */

  while (RAND_status () == 0 && maxrand-- > 0)
    {
