 #define MAX(_a,_b) ((_a)>(_b)?(_a):(_b))
 #endif
 
-#define DEBUGPR(msg) \
-  do if (debug_flag) { print_spaces (depth); printf (msg, file->name); \
-                       fflush (stdout); } while (0)
-
 #ifdef VMS
 # ifndef EXIT_FAILURE
 #  define EXIT_FAILURE 3
