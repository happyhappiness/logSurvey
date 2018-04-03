#endif
  int version;
  version=`(hostinfo | sed -n 's/.*NeXT Mach \([0-9]*\).*/\1/p') 2>/dev/null`;
  printf ("%s-next-nextstep%d\n", __ARCHITECTURE__, version);
  exit (0);
#endif

