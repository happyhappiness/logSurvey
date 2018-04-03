#ifdef __ELF__
# ifdef __GLIBC__
#  if __GLIBC__ >= 2
    printf ("%s-pc-linux-gnu\n", argv[1]);
#  else
    printf ("%s-pc-linux-gnulibc1\n", argv[1]);
#  endif
# else
   printf ("%s-pc-linux-gnulibc1\n", argv[1]);
# endif
#else
  printf ("%s-pc-linux-gnuaout\n", argv[1]);
#endif
  return 0;
}
