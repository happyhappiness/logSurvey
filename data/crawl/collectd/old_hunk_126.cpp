  printf ("ok %i - %s evaluates to %d\n", ++check_count__, #actual, expect); \
} while (0)

#define DBLEQ(expect, actual) do { \
  double e = (expect); double a = (actual); \
  if (isnan (e) && !isnan (a)) { \