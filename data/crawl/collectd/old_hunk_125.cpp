  printf ("ok %i - %s evaluates to \"%s\"\n", ++check_count__, #actual, expect); \
} while (0)

#define EXPECT_INTEQ(expect, actual) do { \
  if ((expect) != (actual)) {\
    printf ("not ok %i - %s incorrect: expected %d, got %d\n", \
