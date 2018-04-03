  printf ("ok %i - %s evaluates to \"%s\"\n", ++check_count__, #actual, expect); \
} while (0)

#define DBLEQ(expect, actual) do { \
  if ((isnan (expect) && !isnan (actual)) || ((expect) != (actual))) {\
    printf ("not ok %i - %s incorrect: expected %.15g, got %.15g\n", \