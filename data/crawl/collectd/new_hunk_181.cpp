  printf ("ok %i - %s = %"PRIu64"\n", ++check_count__, #actual, got__); \
} while (0)

#define EXPECT_EQ_DOUBLE(expect, actual) do { \
  double want__ = (double) expect; \
  double got__  = (double) actual; \
  if (isnan (want__) && !isnan (got__)) { \
    printf ("not ok %i - %s = %.15g, want %.15g\n", \
        ++check_count__, #actual, got__, want__); \
    return (-1); \
  } else if (!isnan (want__) && (((want__-got__) < -DBL_PRECISION) || ((want__-got__) > DBL_PRECISION))) { \
    printf ("not ok %i - %s = %.15g, want %.15g\n", \
        ++check_count__, #actual, got__, want__); \
    return (-1); \
  } \
  printf ("ok %i - %s = %.15g\n", ++check_count__, #actual, got__); \
} while (0)

#define CHECK_NOT_NULL(expr) do { \
