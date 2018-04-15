} while (0)
#define OK(cond) OK1(cond, #cond)

#define STREQ(expect, actual) do { \
  if (strcmp (expect, actual) != 0) { \
    printf ("not ok %i - %s incorrect: expected \"%s\", got \"%s\"\n", \
        ++check_count__, #actual, expect, actual); \
    return (-1); \
  } \
  printf ("ok %i - %s evaluates to \"%s\"\n", ++check_count__, #actual, expect); \
} while (0)

#define EXPECT_EQ(expect, actual, format) do { \
  if ((expect) != (actual)) {\
    printf ("not ok %i - %s incorrect: expected " format ", got " format "\n", \
        ++check_count__, #actual, expect, actual); \
    return (-1); \
  } \
  printf ("ok %i - %s evaluates to " format "\n", ++check_count__, #actual, expect); \
} while (0)

#define EXPECT_INTEQ(expect, actual) do { \
  if ((expect) != (actual)) {\
    printf ("not ok %i - %s incorrect: expected %d, got %d\n", \
        ++check_count__, #actual, expect, actual); \
    return (-1); \
  } \
  printf ("ok %i - %s evaluates to %d\n", ++check_count__, #actual, expect); \
} while (0)

#define EXPECT_EQ_UINT64(expect, actual) do { \
