#define DEBUGPR(msg) \
  do if (debug_flag) { print_spaces (depth); printf (msg, file->name); \
		       fflush (stdout); } while (0)
