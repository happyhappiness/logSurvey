#endif

#if defined (vax)
# if !defined (ultrix)
#  include <sys/param.h>
#  if defined (BSD)
#   if BSD == 43
      printf ("vax-dec-bsd4.3\n"); exit (0);
#   else
#    if BSD == 199006
      printf ("vax-dec-bsd4.3reno\n"); exit (0);
#    else
      printf ("vax-dec-bsd\n"); exit (0);
#    endif
#   endif
#  else
    printf ("vax-dec-bsd\n"); exit (0);
#  endif
# else
    printf ("vax-dec-ultrix\n"); exit (0);
# endif
#endif

#if defined (alliant) && defined (i860)
