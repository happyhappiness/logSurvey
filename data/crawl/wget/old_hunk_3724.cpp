#endif

#if defined (vax)
#if !defined (ultrix)
  printf ("vax-dec-bsd\n"); exit (0);
#else
  printf ("vax-dec-ultrix\n"); exit (0);
#endif
#endif

#if defined (alliant) && defined (i860)
