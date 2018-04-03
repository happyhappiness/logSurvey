} while (0)

#define DBLEQ(expect, actual) do { \
  double e = (expect); double a = (actual); \
  if (isnan (e) && !isnan (a)) { \
    printf ("not ok %i - %s incorrect: expected %.15g, got %.15g\n", \
        ++check_count__, #actual, e, a); \
    return (-1); \
  } else if (!isnan (e) && (((e-a) < -1e-12) || ((e-a) > 1e-12))) { \
    printf ("not ok %i - %s incorrect: expected %.15g, got %.15g\n", \
        ++check_count__, #actual, e, a); \
    return (-1); \
  } \
  printf ("ok %i - %s evaluates to %.15g\n", ++check_count__, #actual, e); \
} while (0)

#define CHECK_NOT_NULL(expr) do { \
