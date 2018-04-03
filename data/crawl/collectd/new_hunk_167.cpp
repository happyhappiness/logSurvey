#define OK(cond) OK1(cond, #cond)

#define EXPECT_EQ_STR(expect, actual) do { \
  /* Evaluate 'actual' only once. */ \
  const char *got__ = actual; \
  if (strcmp (expect, got__) != 0) { \
    printf ("not ok %i - %s = \"%s\", want \"%s\"\n", \
        ++check_count__, #actual, got__, expect); \
    return (-1); \
  } \
  printf ("ok %i - %s = \"%s\"\n", ++check_count__, #actual, got__); \
} while (0)

#define EXPECT_EQ_INT(expect, actual) do { \
