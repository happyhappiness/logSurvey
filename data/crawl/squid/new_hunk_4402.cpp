#endif

#if defined (__arm) && defined (__acorn) && defined (__unix)
  printf ("arm-acorn-riscix"); exit (0);
#endif

#if defined (hp300) && !defined (hpux)
