} while (0)
#define OK(cond) OK1(cond, #cond)

#define EXPECT_EQ_STR(expect, actual) do { \
  if (strcmp (expect, actual) != 0) { \
    printf ("not ok %i - %s = \"%s\", want \"%s\"\n", \
        ++check_count__, #actual, actual, expect); \
    return (-1); \
  } \
  printf ("ok %i - %s = \"%s\"\n", ++check_count__, #actual, actual); \
} while (0)

#define EXPECT_EQ_INT(expect, actual) do { \
  int want__ = (int) expect; \
  int got__  = (int) actual; \
  if (got__ != want__) { \
    printf ("not ok %i - %s = %d, want %d\n", \
        ++check_count__, #actual, got__, want__); \
    return (-1); \
  } \
  printf ("ok %i - %s = %d\n", ++check_count__, #actual, got__); \
} while (0)

#define EXPECT_EQ_UINT64(expect, actual) do { \
