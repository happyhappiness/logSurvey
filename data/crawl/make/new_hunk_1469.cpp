#define DEBUGPR(msg) \
  do if (debug_flag) { print_spaces (depth); printf (msg, file->name); \
		       fflush (stdout); } while (0)

#ifdef VMS
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 3
# endif
# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 1
# endif
# ifndef EXIT_TROUBLE
#  define EXIT_TROUBLE 2
# endif
#else
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 2
# endif
# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif
# ifndef EXIT_TROUBLE
#  define EXIT_TROUBLE 1
# endif
#endif

