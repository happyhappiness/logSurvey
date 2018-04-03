  printf ("ok %i - %s evaluates to \"%s\"\n", ++check_count__, #actual, expect); \
} while (0)

#define CHECK_NOT_NULL(expr) do { \
  void *ptr_; \
  ptr_ = (expr); \