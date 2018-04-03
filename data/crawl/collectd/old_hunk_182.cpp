  printf ("ok %i - %s evaluates to %d\n", ++check_count__, #actual, expect); \
} while (0)

#define EXPECT_EQ_UINT64(expect, actual) EXPECT_EQ((expect), (actual), "%"PRIu64)

#define DBLEQ(expect, actual) do { \
  double e = (expect); double a = (actual); \