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